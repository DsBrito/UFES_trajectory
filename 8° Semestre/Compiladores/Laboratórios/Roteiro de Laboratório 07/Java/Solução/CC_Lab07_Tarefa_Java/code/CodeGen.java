package code;

import static code.Instruction.INSTR_MEM_SIZE;
import static code.OpCode.ADDf;
import static code.OpCode.ADDi;
import static code.OpCode.B2Ss;
import static code.OpCode.BOFb;
import static code.OpCode.CALL;
import static code.OpCode.CATs;
import static code.OpCode.DIVf;
import static code.OpCode.DIVi;
import static code.OpCode.EQUf;
import static code.OpCode.EQUi;
import static code.OpCode.EQUs;
import static code.OpCode.HALT;
import static code.OpCode.I2Ss;
import static code.OpCode.JUMP;
import static code.OpCode.LDIf;
import static code.OpCode.LDIi;
import static code.OpCode.LDWf;
import static code.OpCode.LDWi;
import static code.OpCode.LTHf;
import static code.OpCode.LTHi;
import static code.OpCode.LTHs;
import static code.OpCode.MULf;
import static code.OpCode.MULi;
import static code.OpCode.OROR;
import static code.OpCode.R2Ss;
import static code.OpCode.STWf;
import static code.OpCode.STWi;
import static code.OpCode.SUBf;
import static code.OpCode.SUBi;
import static code.OpCode.WIDf;
import static typing.Type.BOOL_TYPE;
import static typing.Type.INT_TYPE;
import static typing.Type.REAL_TYPE;

import ast.AST;
import ast.ASTBaseVisitor;
import tables.StrTable;
import tables.VarTable;
import typing.Type;

/*
 * Visitador da AST para geração básica de código. Funciona de
 * forma muito similar ao interpretador do laboratório anterior,
 * mas agora estamos trabalhando com um ambiente de execução
 * com código de 3 endereços. Isto quer dizer que não existe mais
 * pilha e todas as operações são realizadas via registradores.
 *
 * Note que não há uma área de memória de dados no código abaixo.
 * Esta área fica agora na TM, que é a "arquitetura" de execução.
 */
public final class CodeGen extends ASTBaseVisitor<Integer> {

	private final Instruction code[]; // Code memory
	private final StrTable st;
	private final VarTable vt;

	// Contadores para geração de código.
	// Próxima posição na memória de código para emit.
	private static int nextInstr;
	// Número de registradores temporários já utilizados.
	// Usamos um valor arbitrário, mas depois seria necessário
	// fazer o processo de alocação de registradores. Isto está
	// fora do escopo da disciplina.
	private static int intRegsCount;
	private static int floatRegsCount;

	public CodeGen(StrTable st, VarTable vt) {
		this.code = new Instruction[INSTR_MEM_SIZE];
		this.st = st;
		this.vt = vt;
	}

	// Função principal para geração de código.
	@Override
	public void execute(AST root) {
		nextInstr = 0;
		intRegsCount = 0;
		floatRegsCount = 0;
	    dumpStrTable();
	    visit(root);
	    emit(HALT);
	    dumpProgram();
	}

	// ----------------------------------------------------------------------------
	// Prints ---------------------------------------------------------------------

	void dumpProgram() {
	    for (int addr = 0; addr < nextInstr; addr++) {
	    	System.out.printf("%s\n", code[addr].toString());
	    }
	}

	void dumpStrTable() {
	    for (int i = 0; i < st.size(); i++) {
	        System.out.printf("SSTR %s\n", st.get(i));
	    }
	}

	// ----------------------------------------------------------------------------
	// Emits ----------------------------------------------------------------------

	private void emit(OpCode op, int o1, int o2, int o3) {
		Instruction instr = new Instruction(op, o1, o2, o3);
		// Em um código para o produção deveria haver uma verificação aqui...
	    code[nextInstr] = instr;
	    nextInstr++;
	}

	private void emit(OpCode op) {
		emit(op, 0, 0, 0);
	}

	private void emit(OpCode op, int o1) {
		emit(op, o1, 0, 0);
	}

	private void emit(OpCode op, int o1, int o2) {
		emit(op, o1, o2, 0);
	}

	private void backpatchJump(int instrAddr, int jumpAddr) {
	    code[instrAddr].o1 = jumpAddr;
	}

	private void backpatchBranch(int instrAddr, int offset) {
	    code[instrAddr].o2 = offset;
	}

	// ----------------------------------------------------------------------------
	// AST Traversal --------------------------------------------------------------

	private int newIntReg() {
		return intRegsCount++;
	}

	private int newFloatReg() {
		return floatRegsCount++;
	}

	// Funcionamento dos visitadores abaixo deve ser razoavelmente explicativo
	// neste final do curso...

	@Override
	protected Integer visitAssign(AST node) {
		AST r = node.getChild(1);
	    int x = visit(r);
	    int addr = node.getChild(0).intData;
	    Type varType = vt.getType(addr);
	    if (varType == REAL_TYPE) {
	        emit(STWf, addr, x);
	    } else { // All other types, include ints, bools and strs.
	        emit(STWi, addr, x);
	    }
	    return -1; // This is not an expression, hence no value to return.
	}

	@Override
	protected Integer visitEq(AST node) {
		AST l = node.getChild(0);
		AST r = node.getChild(1);
		int y = visit(l);
		int z = visit(r);
		int x = newIntReg();
		if (r.type == REAL_TYPE) {  // Could equally test 'l' here.
			emit(EQUf, x, y, z);
		} else if (r.type == INT_TYPE) {
			emit(EQUi, x, y, z);
		} else { // Must be STR_TYPE
	        emit(EQUs, x, y, z);
	    }
	    return x;
	}

	@Override
	protected Integer visitBlock(AST node) {
	    for (int i = 0; i < node.getChildCount(); i++) {
	        visit(node.getChild(i));
	    }
	    return -1; // This is not an expression, hence no value to return.
	}

	@Override
	protected Integer visitBoolVal(AST node) {
		int x = newIntReg();
	    int c = node.intData;
	    emit(LDIi, x, c);
	    return x;
	}

	@Override
	protected Integer visitIf(AST node) {
		// Code for test.
	    int testReg = visit(node.getChild(0));
	    int condJumpInstr = nextInstr;
	    emit(BOFb, testReg, 0); // Leave offset empty now, will be backpatched.

	    // Code for TRUE block.
	    int trueBranchStart = nextInstr;
	    visit(node.getChild(1)); // Generate TRUE block.

	    // Code for FALSE block.
	    int falseBranchStart;
	    if (node.getChildCount() == 3) { // We have an else.
	        // Emit unconditional jump for TRUE block.
	        int uncondJumpInstr = nextInstr;
	        emit(JUMP, 0); // Leave address empty now, will be backpatched.
	        falseBranchStart = nextInstr;
	        visit(node.getChild(2)); // Generate FALSE block.
	        // Backpatch unconditional jump at end of TRUE block.
	        backpatchJump(uncondJumpInstr, nextInstr);
	    } else {
	    	falseBranchStart = nextInstr;
	    }

	    // Backpatch test.
	    backpatchBranch(condJumpInstr, falseBranchStart - trueBranchStart + 1);

	    return -1; // This is not an expression, hence no value to return.
	}

	@Override
	protected Integer visitIntVal(AST node) {
		int x = newIntReg();
	    int c = node.intData;
	    emit(LDIi, x, c);
	    return x;
	}

	@Override
	protected Integer visitLt(AST node) {
		AST l = node.getChild(0);
		AST r = node.getChild(1);
		int y = visit(l);
		int z = visit(r);
		int x = newIntReg();
		if (r.type == REAL_TYPE) {  // Could equally test 'l' here.
			emit(LTHf, x, y, z);
		} else if (r.type == INT_TYPE) {
			emit(LTHi, x, y, z);
		} else { // Must be STR_TYPE
	        emit(LTHs, x, y, z);
	    }
	    return x;
	}

	@Override
	protected Integer visitMinus(AST node) {
		int x;
	    int y = visit(node.getChild(0));
	    int z = visit(node.getChild(1));
	    if (node.type == REAL_TYPE) {
	        x = newFloatReg();
	        emit(SUBf, x, y, z);
	    } else {
	        x = newIntReg();
	        emit(SUBi, x, y, z);
	    }
	    return x;
	}

	@Override
	protected Integer visitOver(AST node) {
		int x;
	    int y = visit(node.getChild(0));
	    int z = visit(node.getChild(1));
	    if (node.type == REAL_TYPE) {
	        x = newFloatReg();
	        emit(DIVf, x, y, z);
	    } else {
	        x = newIntReg();
	        emit(DIVi, x, y, z);
	    }
	    return x;
	}

	@Override
	protected Integer visitPlus(AST node) {
		int x;
	    int y = visit(node.getChild(0));
	    int z = visit(node.getChild(1));
	    if (node.type == REAL_TYPE) {
	        x = newFloatReg();
	        emit(ADDf, x, y, z);
	    } else if (node.type == INT_TYPE) {
	    	x = newIntReg();
	        emit(ADDi, x, y, z);
	    } else if (node.type == BOOL_TYPE) {
	    	x = newIntReg();
	        emit(OROR, x, y, z);
	    } else { // Must be STR_TYPE
	    	x = newIntReg();
	        emit(CATs, x, y, z);
	    }
	    return x;
	}

	@Override
	protected Integer visitProgram(AST node) {
		visit(node.getChild(0)); // var_list
		visit(node.getChild(1)); // block
	    return -1;  // This is not an expression, hence no value to return.
	}

	@Override
	protected Integer visitRead(AST node) {
		AST var = node.getChild(0);
	    int addr = var.intData;
	    int x;
	    if (var.type == INT_TYPE) {
	    	x = newIntReg();
	        emit(CALL, 0, x);
	        emit(STWi, addr, x);
	    } else if (var.type == REAL_TYPE) {
	        x = newFloatReg();
	        emit(CALL, 1, x);
	        emit(STWf, addr, x);
	    } else if (var.type == BOOL_TYPE) {
	    	x = newIntReg();
	        emit(CALL, 2, x);
	        emit(STWi, addr, x);
	    } else { // Must be STR_TYPE
	    	x = newIntReg();
	        emit(CALL, 3, x);
	        emit(STWi, addr, x);
	    }
	    return -1;  // This is not an expression, hence no value to return.
	}

	@Override
	protected Integer visitRealVal(AST node) {
		int x = newFloatReg();
	    // We need to read as an int because the TM cannot handle floats directly.
	    // But we have a float stored in the AST, so we just convert it as an int
	    // and magically we have a float encoded as an int... :P
	    int c = Float.floatToIntBits(node.floatData);
	    emit(LDIf, x, c);
	    return x;
	}

	@Override
	protected Integer visitRepeat(AST node) {
		int beginRepeat = nextInstr;
	    visit(node.getChild(0)); // Emit code for body.
	    int testReg = visit(node.getChild(1)); // Emit code for test.
	    emit(BOFb, testReg, beginRepeat - nextInstr);
	    return -1;  // This is not an expression, hence no value to return.
	}

	@Override
	protected Integer visitStrVal(AST node) {
		int x = newIntReg();
	    int c = node.intData;
	    emit(LDIi, x, c);
	    return x;
	}

	@Override
	protected Integer visitTimes(AST node) {
		int x;
	    int y = visit(node.getChild(0));
	    int z = visit(node.getChild(1));
	    if (node.type == REAL_TYPE) {
	        x = newFloatReg();
	        emit(MULf, x, y, z);
	    } else {
	        x = newIntReg();
	        emit(MULi, x, y, z);
	    }
	    return x;
	}

	@Override
	protected Integer visitVarDecl(AST node) {
		// Nothing to do here.
	    return -1;  // This is not an expression, hence no value to return.
	}

	@Override
	protected Integer visitVarList(AST node) {
		// Nothing to do here.
	    return -1;  // This is not an expression, hence no value to return.
	}

	@Override
	protected Integer visitVarUse(AST node) {
		int addr = node.intData;
	    int x;
	    if (node.type == REAL_TYPE) {
	        x = newFloatReg();
	        emit(LDWf, x, addr);
	    } else {
	        x = newIntReg();
	        emit(LDWi, x, addr);
	    }
	    return x;
	}

	@Override
	protected Integer visitWrite(AST node) {
		AST expr = node.getChild(0);
	    int x = visit(expr);
	    switch(expr.type) {
	        case INT_TYPE:  emit(CALL, 4, x);  break;
	        case REAL_TYPE: emit(CALL, 5, x);  break;
	        case BOOL_TYPE: emit(CALL, 6, x);  break;
	        case STR_TYPE:  emit(CALL, 7, x);  break;
	        case NO_TYPE:
	        default:
	            System.err.printf("Invalid type: %s!\n", expr.type.toString());
	            System.exit(1);
	    }
	    return -1;  // This is not an expression, hence no value to return.
	}

	@Override
	protected Integer visitB2I(AST node) {
		int x = visit(node.getChild(0));
	    // Nothing else to do, a bool already is stored as an int.
	    return x;
	}

	@Override
	protected Integer visitB2R(AST node) {
		int i = visit(node.getChild(0));
	    int r = newFloatReg();
	    emit(WIDf, r, i);
	    return r;
	}

	@Override
	protected Integer visitB2S(AST node) {
		int x = newIntReg();
	    int y = visit(node.getChild(0));
	    emit(B2Ss, x, y);
	    return x;
	}

	@Override
	protected Integer visitI2R(AST node) {
		int i = visit(node.getChild(0));
	    int r = newFloatReg();
	    emit(WIDf, r, i);
	    return r;
	}

	@Override
	protected Integer visitI2S(AST node) {
		int x = newIntReg();
	    int y = visit(node.getChild(0));
	    emit(I2Ss, x, y);
	    return x;
	}

	@Override
	protected Integer visitR2S(AST node) {
		int x = newIntReg();
	    int y = visit(node.getChild(0));
	    emit(R2Ss, x, y);
	    return x;
	}

}

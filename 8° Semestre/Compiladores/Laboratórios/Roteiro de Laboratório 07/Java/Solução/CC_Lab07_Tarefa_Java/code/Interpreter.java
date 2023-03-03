package code;

import static typing.Type.INT_TYPE;
import static typing.Type.REAL_TYPE;

import java.io.IOException;
import java.io.StreamTokenizer;
import java.io.StringReader;
import java.util.Scanner;

import ast.AST;
import ast.ASTBaseVisitor;
import tables.StrTable;
import tables.VarTable;
import typing.Type;

/*
 * Interpretador de código para EZLang, implementado como
 * um visitador da AST gerada pelo front-end. Tipo genérico
 * foi instanciado para Void porque a gente não precisa de
 * um valor de retorno na visitação. Para o gerador de código
 * do próximo laboratório isso vai mudar.
 * Para rodar, chame o método 'execute' da superclasse.
 */
public final class Interpreter extends ASTBaseVisitor<Void> {

	// Tudo privado e final para simplificar.
	private final DataStack stack;
	private final Memory memory;
	private final StrTable st;
	private final VarTable vt;
	private final Scanner in; // Para leitura de stdin
	
	// Construtor basicão.
	public Interpreter(StrTable st, VarTable vt) {
		this.stack = new DataStack();
		this.memory = new Memory(vt);
		this.st = st;
		this.vt = vt;
		this.in = new Scanner(System.in);
	}
	
	// -------------------------------------------------------
	// Daqui para frente são os métodos especializados de cada
	// nó. O código deve ser mais ou menos auto-explicativo.
	// Estou assumindo que nessa altura de tudo você já está
	// ninja dos caminhamentos em árvores...
	
	@Override
	protected Void visitAssign(AST node) {
		// Visita recursivamente a expressão da direita para
		// calcular o seu valor, que vai ficar no topo da pilha.
		AST rexpr = node.getChild(1);
		visit(rexpr);
		// Armazena o valor da pilha na memória, conforme o tipo
		// da variável.
		int varIdx = node.getChild(0).intData;
		Type varType = vt.getType(varIdx);
		if (varType == REAL_TYPE) {
			memory.storef(varIdx, stack.popf());
		} else {
			memory.storei(varIdx, stack.popi());
		}
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	@Override
	protected Void visitEq(AST node) {
		// Executa as subexpressões cujos valores vão ficar na pilha.
		AST lexpr = node.getChild(0);
		AST rexpr = node.getChild(1);
		visit(lexpr);
		visit(rexpr);
		// Poderia usar 'lexpr' também no teste abaixo, já que
		// ambos os lados são garantidamente do mesmo tipo,
		// por conta dos eventuais nós de conversão.
		if (rexpr.type == INT_TYPE) {
			int r = stack.popi();
	        int l = stack.popi();
	        stack.pushi(l == r ? 1 : 0); // 1 = true; 0 = false
		} else if (rexpr.type == REAL_TYPE) {
			float r = stack.popf();
	        float l = stack.popf();
	        stack.pushi(l == r ? 1 : 0);
		} else { // Must be STR_TYPE
			int r = stack.popi();
	        int l = stack.popi();
	        String ls = st.get(l);
	        String rs = st.get(r);
	        stack.pushi(ls.compareTo(rs) == 0 ? 1 : 0);
		}
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	@Override
	protected Void visitBlock(AST node) {
		// Visita todos os filhos do bloco na ordem.
		for (int i = 0; i < node.getChildCount(); i++) {
			visit(node.getChild(i));
		}
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	@Override
	protected Void visitBoolVal(AST node) {
		// Base da recursão.
		stack.pushi(node.intData);
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	@Override
	protected Void visitIf(AST node) {
		// Visita a expressão de teste.
		visit(node.getChild(0));
		int test = stack.popi();
		if (test == 1) { // THEN
			visit(node.getChild(1));
		} else if (test == 0 && node.getChildCount() == 3) { // ELSE, se houver
			visit(node.getChild(2));
		}
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	@Override
	protected Void visitIntVal(AST node) {
		// Base da recursão.
		stack.pushi(node.intData);
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	@Override
	protected Void visitLt(AST node) {
		AST lexpr = node.getChild(0);
		AST rexpr = node.getChild(1);
		visit(lexpr);
		visit(rexpr);
		// Poderia usar 'lexpr' também no teste abaixo, já que
		// ambos os lados são garantidamente do mesmo tipo,
		// por conta dos eventuais nós de conversão.
		if (rexpr.type == INT_TYPE) {
			int r = stack.popi();
	        int l = stack.popi();
	        stack.pushi(l < r ? 1 : 0);
		} else if (rexpr.type == REAL_TYPE) {
			float r = stack.popf();
	        float l = stack.popf();
	        stack.pushi(l < r ? 1 : 0);
		} else { // Must be STR_TYPE
			int r = stack.popi();
	        int l = stack.popi();
	        String ls = st.get(l);
	        String rs = st.get(r);
	        stack.pushi(ls.compareTo(rs) < 0 ? 1 : 0);
		}
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	@Override
	protected Void visitMinus(AST node) {
		visit(node.getChild(0));
		visit(node.getChild(1));
		if (node.type == INT_TYPE) {
	        int r = stack.popi();
	        int l = stack.popi();
	        stack.pushi(l - r);
	    } else { // Result must be REAL_TYPE.
	        float r = stack.popf();
	        float l = stack.popf();
	        stack.pushf(l - r);
	    }
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	@Override
	protected Void visitOver(AST node) {
		visit(node.getChild(0));
		visit(node.getChild(1));
		if (node.type == INT_TYPE) {
	        int r = stack.popi();
	        int l = stack.popi();
	        stack.pushi(l / r);
	    } else { // Result must be REAL_TYPE.
	        float r = stack.popf();
	        float l = stack.popf();
	        stack.pushf(l / r);
	    }
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	@Override
	protected Void visitPlus(AST node) {
		// Poderia fazer tudo em um método só mas como o '+'
		// é sobrecarregado, preferi dividir em métodos auxiliares.
		switch(node.type) {
			case INT_TYPE:  plusInt(node);    break;
	        case REAL_TYPE: plusReal(node);   break;
	        case BOOL_TYPE: plusBool(node);   break;
	        case STR_TYPE:  plusStr(node);    break;
			case NO_TYPE:
		    default:
	            System.err.printf("Invalid type: %s!\n",node.type.toString());
	            System.exit(1);
		}
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	private Void plusInt(AST node) {
		visit(node.getChild(0));
		visit(node.getChild(1));
	    int r = stack.popi();
	    int l = stack.popi();
	    stack.pushi(l + r);
	    return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	private Void plusReal(AST node) {
		visit(node.getChild(0));
		visit(node.getChild(1));
	    float r = stack.popf();
	    float l = stack.popf();
	    stack.pushf(l + r);
	    return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	private Void plusBool(AST node) {
		visit(node.getChild(0));
		visit(node.getChild(1));
	    int r = stack.popi();
	    int l = stack.popi();
	    if (l == 1 || r == 1) {
	    	stack.pushi(1); // true
	    } else {
	    	stack.pushi(0); // false
	    }
	    return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	private Void plusStr(AST node) {
		visit(node.getChild(0));
		visit(node.getChild(1));
	    int r = stack.popi();
	    int l = stack.popi();
	    String ls = st.get(l);
	    String rs = st.get(r);
	    StringBuilder sb = new StringBuilder();
	    // Todas as strings ficam envoltas por ", por isso,
	    // na hora de concatenar, precisamos retirar o último
	    // caractere da substring da esquerda...
	    sb.append(ls.substring(0, ls.length() - 1));
	    // ...e o primeiro caractere da substring da direita. 
	    sb.append(rs.substring(1));
	    // Adiciona a nova string na tabela.
	    int newStrIdx = st.addStr(sb.toString());
	    // Retorna o índice da nova string pela pilha.
	    stack.pushi(newStrIdx);
	    return null; // Java exige um valor de retorno mesmo para Void... :/
    }

	@Override
	protected Void visitProgram(AST node) {
		visit(node.getChild(0)); // run var_list
		visit(node.getChild(1)); // run block
		in.close(); // Fim do programa, não precisa mais de ler de stdin.
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	@Override
	protected Void visitRead(AST node) {
		int varIdx = node.getChild(0).intData;
		Type varType = vt.getType(varIdx);
		switch(varType) {
			case INT_TYPE:  readInt(varIdx);    break;
	        case REAL_TYPE: readReal(varIdx);   break;
	        case BOOL_TYPE: readBool(varIdx);   break;
	        case STR_TYPE:  readStr(varIdx);    break;
			case NO_TYPE:
		    default:
	            System.err.printf("Invalid type: %s!\n", varType.toString());
	            System.exit(1);
		}
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	private Void readInt(int varIdx) {
		System.out.printf("read (int): ");
		int value = in.nextInt();
		memory.storei(varIdx, value);
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	private Void readReal(int varIdx) {
		System.out.printf("read (real): ");
		float value = in.nextFloat();
		memory.storef(varIdx, value);
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	private Void readBool(int varIdx) {
		int value;
	    do {
	        System.out.printf("read (bool - 0 = false, 1 = true): ");
	        value = in.nextInt();
	    } while (value != 0 && value != 1);
	    memory.storei(varIdx, value);
	    return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	private Void readStr(int varIdx) {
		System.out.printf("read (str): ");
		String s = in.next();
		int strIdx = st.addStr(s);
		memory.storei(varIdx, strIdx);
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	@Override
	protected Void visitRealVal(AST node) {
		stack.pushf(node.floatData);
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	@Override
	protected Void visitRepeat(AST node) {
		// Usando um loop para implementar um loop, que coisa "meta" isso... :P
		int again = 1;
	    while (again == 1) {
	    	visit(node.getChild(0)); // run body
			visit(node.getChild(1)); // run test
	        again = (stack.popi() == 0? 1 : 0); // again = !popi();
	    }
	    return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	@Override
	protected Void visitStrVal(AST node) {
		stack.pushi(node.intData);
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	@Override
	protected Void visitTimes(AST node) {
		visit(node.getChild(0));
		visit(node.getChild(1));
		if (node.type == INT_TYPE) {
	        int r = stack.popi();
	        int l = stack.popi();
	        stack.pushi(l * r);
	    } else { // Result must be REAL_TYPE.
	        float r = stack.popf();
	        float l = stack.popf();
	        stack.pushf(l * r);
	    }
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	@Override
	protected Void visitVarDecl(AST node) {
		// Nothing to do.
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	@Override
	protected Void visitVarList(AST node) {
		// Nothing to do.
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	@Override
	protected Void visitVarUse(AST node) {
		int varIdx = node.intData;
		if (node.type == REAL_TYPE) {
			stack.pushf(memory.loadf(varIdx));
		} else {
			stack.pushi(memory.loadi(varIdx));
		}
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	@Override
	protected Void visitWrite(AST node) {
		AST expr = node.getChild(0);
		visit(expr);
		switch(expr.type) {
			case INT_TYPE:  writeInt();    break;
	        case REAL_TYPE: writeReal();   break;
	        case BOOL_TYPE: writeBool();   break;
	        case STR_TYPE:  writeStr();    break;
			case NO_TYPE:
		    default:
	            System.err.printf("Invalid type: %s!\n", expr.type.toString());
	            System.exit(1);
		}
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	private Void writeInt() {
		System.out.println(stack.popi());
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	private Void writeReal() {
		System.out.println(stack.popf());
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	private Void writeBool() {
		if (stack.popi() == 0) {
			System.out.println("false");
		} else {
			System.out.println("true");
		}
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	private Void writeStr() {
		int strIdx = stack.popi(); // String pointer
		String originalStr = st.get(strIdx);
		String unescapedStr = unescapeStr(originalStr);
		System.out.print(unescapedStr);
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	// Função auxiliar para converter a string com escapes.
	// Há várias formas de se fazer isso em Java mas preferi
	// deixar assim para não precisar de bibliotecas ou de uma
	// versão do Java mais recente.
	// Se você preferir, pode usar:
	// org.apache.commons.lang.StringEscapeUtils.unescapeJava()
	// ou
	// String.translateEscapes(), disponível a partir do Java 15.
	private String unescapeStr(String originalStr) {
		StreamTokenizer parser = new StreamTokenizer(new StringReader(originalStr));
		String unescapedStr = "";
		try {
		    parser.nextToken();
		    if (parser.ttype == '"') {
			    unescapedStr = parser.sval;
		    } else {
			  unescapedStr = "ERROR at string conversion!";
		    }
		}
		catch (IOException e) {
		    e.printStackTrace();
		}
		return unescapedStr;
	}
	
	@Override
	protected Void visitB2I(AST node) {
		visit(node.getChild(0));
	    // Nothing else to do, a bool already is stored as an int.
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	@Override
	protected Void visitB2R(AST node) {
		visit(node.getChild(0));
		stack.pushf((float) stack.popi());
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	@Override
	protected Void visitB2S(AST node) {
		visit(node.getChild(0));
		String s;
		if (stack.popi() == 0) {
			s = '"' + Boolean.toString(false) + '"';
		} else {
			s = '"' + Boolean.toString(true) + '"';
		}
		stack.pushi(st.addStr(s));
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	@Override
	protected Void visitI2R(AST node) {
		visit(node.getChild(0));
		stack.pushf((float) stack.popi());
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	@Override
	protected Void visitI2S(AST node) {
		visit(node.getChild(0));
		String s = '"' + Integer.toString(stack.popi()) + '"';
		stack.pushi(st.addStr(s));
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	@Override
	protected Void visitR2S(AST node) {
		visit(node.getChild(0));
		String s = '"' + Float.toString(stack.popf()) + '"';
		stack.pushi(st.addStr(s));
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

}

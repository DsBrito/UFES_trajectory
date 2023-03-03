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
 *
 * Para rodar, chame o método 'execute' da superclasse.
 */
public class Interpreter extends ASTBaseVisitor<Void> {

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

	// TODO
	@Override
	protected Void visitAssign(AST node) {
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	// TODO
	@Override
	protected Void visitEq(AST node) {
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	// TODO
	@Override
	protected Void visitBlock(AST node) {
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	// TODO
	@Override
	protected Void visitBoolVal(AST node) {
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	// TODO
	@Override
	protected Void visitIf(AST node) {
        return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	// TODO
	@Override
	protected Void visitIntVal(AST node) {
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	// TODO
	@Override
	protected Void visitLt(AST node) {
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	// TODO
	@Override
	protected Void visitMinus(AST node) {
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	// TODO
	@Override
	protected Void visitOver(AST node) {
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	// TODO
	@Override
	protected Void visitPlus(AST node) {
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	@Override
	protected Void visitProgram(AST node) {
		visit(node.getChild(0)); // run var_list
		visit(node.getChild(1)); // run block
		in.close(); // Fim do programa, não precisa mais de ler de stdin.
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	// TODO
	@Override
	protected Void visitRead(AST node) {
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	// Funções auxiliares para implementar 'visitRead'.

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

	// TODO
	@Override
	protected Void visitRealVal(AST node) {
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	// TODO
	@Override
	protected Void visitRepeat(AST node) {
	    return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	@Override
	protected Void visitStrVal(AST node) {
		stack.pushi(node.intData);
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	// TODO
	@Override
	protected Void visitTimes(AST node) {
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

	// TODO
	@Override
	protected Void visitVarUse(AST node) {
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	// TODO
	@Override
	protected Void visitWrite(AST node) {
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	// Funções auxiliares para implementar 'visitWrite'.

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

	// TODO
	@Override
	protected Void visitB2I(AST node) {
		return null; // Java exige um valor de retorno mesmo para Void... :/
	}

	// TODO
	@Override
	protected Void visitB2R(AST node) {
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

	// TODO
	@Override
	protected Void visitI2R(AST node) {
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

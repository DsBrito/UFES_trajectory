
import java.io.IOException;

import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CharStreams;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.ParseTree;

import checker.SemanticChecker;
import code.Interpreter;
import parser.EZLexer;
import parser.EZParser;

public class Main {

	/*
	 *  Programa principal para funcionamento do compilador.
	 *
	 *  Esta função espera um único argumento: o nome do
	 *  programa a ser compilado. Em um código real certamente
	 *  deveria haver alguma verificação de erro mas ela foi
	 *  omitida aqui para simplificar o código e facilitar a leitura.
	 */
	public static void main(String[] args) throws IOException {
		// Cria um CharStream que lê os caracteres de um arquivo.
		// O livro do ANTLR fala para criar um ANTLRInputStream,
		// mas a partir da versão 4.7 essa classe foi deprecada.
		// Esta é a forma atual para criação do stream.
		CharStream input = CharStreams.fromFileName(args[0]);

		// Cria um lexer que consome a entrada do CharStream.
		EZLexer lexer = new EZLexer(input);

		// Cria um buffer de tokens vindos do lexer.
		CommonTokenStream tokens = new CommonTokenStream(lexer);

		// Cria um parser que consome os tokens do buffer.
		EZParser parser = new EZParser(tokens);

		// Começa o processo de parsing na regra 'program'.
		ParseTree tree = parser.program();

		if (parser.getNumberOfSyntaxErrors() != 0) {
			// Houve algum erro sintático. Termina a compilação aqui.
			return;
		}

		// Cria o analisador semântico e visita a ParseTree para
		// fazer a análise.
		SemanticChecker checker = new SemanticChecker();
		checker.visit(tree);

		// Saída final. Se chegou até aqui é porque não houve erro.
		// Executa o interpretador de código.
		Interpreter interpreter = new Interpreter(checker.st, checker.vt);
		interpreter.execute(checker.getAST());
	}

}

import java.io.IOException;

import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CharStreams;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.ParseTree;

import calc.Calculator;
import parser.Exemplo02Lexer;
import parser.Exemplo02Parser;

public class Main {

	public static void main(String[] args) throws IOException {
		// Cria um CharStream que lê os caracteres de stdin.
		CharStream input = CharStreams.fromStream(System.in);

		// Cria um lexer que consome a entrada do CharStream.
		Exemplo02Lexer lexer = new Exemplo02Lexer(input);

		// Cria um buffer de tokens vindos do lexer.
		CommonTokenStream tokens = new CommonTokenStream(lexer);

		// Cria um parser que consome os tokens do buffer.
		Exemplo02Parser parser = new Exemplo02Parser(tokens);

		// Começa o processo de parsing na regra 'line'.
		ParseTree tree = parser.line();

		if (parser.getNumberOfSyntaxErrors() != 0) {
			// Houve algum erro sintático. Termina a compilação aqui.
			return;
		}

		// Cria a calculadora e visita a ParseTree para computar.
		Calculator calc = new Calculator();
		int result = calc.visit(tree);

		// Saída final.
		System.out.println("Result = " + result);
	}

}

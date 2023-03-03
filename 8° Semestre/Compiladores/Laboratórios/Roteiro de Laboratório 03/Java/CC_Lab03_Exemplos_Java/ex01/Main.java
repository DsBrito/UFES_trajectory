import java.io.IOException;

import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CharStreams;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.ParseTree;

import calc.Calculator;
import parser.Exemplo01Lexer;
import parser.Exemplo01Parser;

public class Main {

    public static void main(String[] args) throws IOException {
        // Cria um CharStream que le os caracteres de stdin.
        CharStream input = CharStreams.fromStream(System.in);
        // Cria um lexer que consome a entrada do CharStream.
        Exemplo01Lexer lexer = new Exemplo01Lexer(input);
        // Cria um buffer de tokens vindos do lexer.
        CommonTokenStream tokens = new CommonTokenStream(lexer);
        // Cria um parser que consome os tokens do buffer.
        Exemplo01Parser parser = new Exemplo01Parser(tokens);
        // Inicia o processo de parsing na regra 'expr'.
        ParseTree tree = parser.expr();
        if (parser.getNumberOfSyntaxErrors() != 0) {
            // Houve um erro sintatico. Termina a compilacao aqui.
            return;
        }
        // Cria a calculadora e visita a ParseTree para computar.
        Calculator calc = new Calculator();
        int result = calc.visit(tree);
        // Saida final.
        System.out.println("Result = " + result);
    }

}

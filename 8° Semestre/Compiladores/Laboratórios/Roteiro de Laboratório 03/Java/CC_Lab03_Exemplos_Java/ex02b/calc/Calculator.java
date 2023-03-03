package calc;

import parser.Exemplo02Parser;
import parser.Exemplo02BaseVisitor;

public class Calculator extends Exemplo02BaseVisitor<Integer> {

// Visita a regra expr: expr (TIMES | OVER) expr
public Integer visitTimesOver(Exemplo02Parser.TimesOverContext ctx){
    // Visita recursivamente a expressao da esquerda
    int l = visit(ctx.expr(0));
    // Visita recursivamente a expressao da direita
    int r = visit(ctx.expr(1));
    // Como saber qual dos dois operadores foi usado?
    return 0;
 }

    // Visita a regra expr: expr (PLUS | MINUS) expr
    @Override
    public Integer visitPlusMinus(Exemplo02Parser.PlusMinusContext ctx) {
        // Visita recursivamente a expressão da esquerda
		int l = visit(ctx.expr(0));
        // Visita recursivamente a expressão da direita
        int r = visit(ctx.expr(1));
        // Como saber qual dos dois operadores foi usado?
        return 0;
    }

    // Visita a regra expr: NUMBER
    @Override
    public Integer visitNumber(Exemplo02Parser.NumberContext ctx) {
        return Integer.parseInt(ctx.NUMBER().getText());
    }
}

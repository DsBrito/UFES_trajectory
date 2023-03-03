package calc;

import parser.Exemplo01Parser;
import parser.Exemplo01BaseVisitor;

public class Calculator extends Exemplo01BaseVisitor<Integer> {

    // Visita a regra expr: term PLUS term
    public Integer visitExpr(Exemplo01Parser.ExprContext ctx) {
        // Visita recursivamente a expressao da esquerda
        int l = visit(ctx.term(0));
        // Visita recursivamente a expressao da direita
        int r = visit(ctx.term(1));
        return l + r;
    }

    // Visita a regra term: factor TIMES factor
    @Override
    public Integer visitTerm(Exemplo01Parser.TermContext ctx) {
        // Visita recursivamente a expressao da esquerda
        int l = visit(ctx.factor(0));
        // Visita recursivamente a expressao da direita
        int r = visit(ctx.factor(1));
        return l * r;
    }

    // Visita a regra factor: NUMBER
    @Override
    public Integer visitFactor(Exemplo01Parser.FactorContext ctx) {
        return Integer.parseInt(ctx.NUMBER().getText());
    }

}

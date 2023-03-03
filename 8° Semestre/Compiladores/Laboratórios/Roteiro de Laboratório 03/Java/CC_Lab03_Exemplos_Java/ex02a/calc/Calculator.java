package calc;

import parser.Exemplo02Parser;
import parser.Exemplo02BaseVisitor;

public class Calculator extends Exemplo02BaseVisitor<Integer> {

    // Como visitar a regra expr? São várias!
    public Integer visitExpr(Exemplo02Parser.ExprContext ctx) {
        return 0;
    }

}

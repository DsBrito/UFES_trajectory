package checker;

import static typing.Type.BOOL_TYPE;
import static typing.Type.INT_TYPE;
import static typing.Type.NO_TYPE;
import static typing.Type.REAL_TYPE;
import static typing.Type.STR_TYPE;

import org.antlr.v4.runtime.Token;

import parser.EZParser;
import parser.EZParser.Assign_stmtContext;
import parser.EZParser.EqLtContext;
import parser.EZParser.ExprFalseContext;
import parser.EZParser.ExprIdContext;
import parser.EZParser.ExprIntValContext;
import parser.EZParser.ExprParContext;
import parser.EZParser.ExprRealValContext;
import parser.EZParser.ExprStrValContext;
import parser.EZParser.ExprTrueContext;
import parser.EZParser.If_stmtContext;
import parser.EZParser.PlusMinusContext;
import parser.EZParser.Read_stmtContext;
import parser.EZParser.Repeat_stmtContext;
import parser.EZParser.TimesOverContext;
import parser.EZParserBaseVisitor;
import tables.StrTable;
import tables.VarTable;
import typing.Type;

/*
 * Analisador semântico de EZLang implementado como um visitor
 * da ParseTree do ANTLR. A classe EZParserBaseVisitor é gerada
 * automaticamente e já possui métodos padrão aonde o comportamento
 * é só visitar todos os filhos. Por conta disto, basta sobreescrever
 * os métodos que a gente quer alterar.
 *
 * Lembre que em um 'visitor' você é responsável por definir o
 * caminhamento nos filhos de um nó da ParseTree através da chamada
 * recursiva da função 'visit'. Ao contrário do 'listener' que
 * caminha automaticamente em profundidade pela ParseTree, se
 * você não chamar 'visit' nos métodos de visitação, o caminhamento
 * para no nó que você estiver, deixando toda a subárvore do nó atual
 * sem visitar. Tome cuidado neste ponto pois isto é uma fonte
 * muito comum de erros. Veja o método visitAssign_stmt abaixo para
 * ter um exemplo.
 *
 * No laboratório anterior, foi usado Void no tipo genérico do
 * EZParserBaseVisitor porque a gente só estava fazendo uma verificação
 * simples das variáveis usando a tabela de símbolos. Mas agora a
 * gente precisa fazer verificação e inferência dos tipos primitivos
 * nas expressões e demais comandos da linguagem. Isto deve ser feito de
 * forma recursiva, caminhando pela árvore. Assim, ao visitar um nó,
 * propagamos para cima o tipo associado a ele, através do valor de retorno
 * da função de visitação. Desta forma, ao terminar o caminhamento todos
 * os nós foram analisados. Por isso que o tipo declarado agora é Type.
 *
 * Note que a EZLang faz uma diferenciação entre comandos e expressões.
 * Só estas últimas possuem tipos. Como todas as funções do visitador
 * agora precisam retornar um tipo, para os comandos que não possuem tipos,
 * retornamos NO_TYPE. Esse mesmo valor de retorno é usado para indicar
 * erros de tipos.
 */
public class SemanticChecker extends EZParserBaseVisitor<Type> {

	private StrTable st = new StrTable();   // Tabela de strings.
    private VarTable vt = new VarTable();   // Tabela de variáveis.

    Type lastDeclType;  // Variável "global" com o último tipo declarado.

    // Testa se o dado token foi declarado antes.
    Type checkVar(Token token) {
    	String text = token.getText();
    	int line = token.getLine();
   		int idx = vt.lookupVar(text);
    	if (idx == -1) {
    		System.err.printf("SEMANTIC ERROR (%d): variable '%s' was not declared.\n", line, text);
    		System.exit(1);
            return NO_TYPE; // Never reached.
        }
    	return vt.getType(idx);
    }

    // Cria uma nova variável a partir do dado token.
    void newVar(Token token) {
    	String text = token.getText();
    	int line = token.getLine();
   		int idx = vt.lookupVar(text);
        if (idx != -1) {
        	System.err.printf("SEMANTIC ERROR (%d): variable '%s' already declared at line %d.\n", line, text, vt.getLine(idx));
        	System.exit(1);
        }
        vt.addVar(text, line, lastDeclType);
    }

    // ----------------------------------------------------------------------------
    // Type checking and inference.

    private void typeError(int lineNo, String op, Type t1, Type t2) {
    	System.out.printf("SEMANTIC ERROR (%d): incompatible types for operator '%s', LHS is '%s' and RHS is '%s'.\n",
    			lineNo, op, t1.toString(), t2.toString());
        System.exit(1);
    }

    // Essa função também poderia virar uma tabela de unificação dos tipos,
    // igual às que estão em Type, mas fica aqui como uma outra forma de implementar
    // a verificação de tipos.
    private void checkAssign(int lineNo, Type l, Type r) {
        if (l == BOOL_TYPE && r != BOOL_TYPE) typeError(lineNo, ":=", l, r);
        if (l == STR_TYPE  && r != STR_TYPE)  typeError(lineNo, ":=", l, r);
        if (l == INT_TYPE  && r != INT_TYPE)  typeError(lineNo, ":=", l, r);
        if (l == REAL_TYPE && !(r == INT_TYPE || r == REAL_TYPE)) typeError(lineNo, ":=", l, r);
    }

    private void checkBoolExpr(int lineNo, String cmd, Type t) {
        if (t != BOOL_TYPE) {
            System.out.printf("SEMANTIC ERROR (%d): conditional expression in '%s' is '%s' instead of '%s'.\n",
               lineNo, cmd, t.toString(), BOOL_TYPE.toString());
            System.exit(1);
        }
    }

    // ----------------------------------------------------------------------------

    // Exibe o conteúdo das tabelas em stdout.
    public void printTables() {
        System.out.print("\n\n");
        System.out.print(st);
        System.out.print("\n\n");
    	System.out.print(vt);
    	System.out.print("\n\n");
    }

    // Visita a regra type_spec: BOOL
    @Override
    public Type visitBoolType(EZParser.BoolTypeContext ctx) {
    	this.lastDeclType = Type.BOOL_TYPE;
    	return NO_TYPE;
    }

    // Visita a regra type_spec: INT
	@Override
	public Type visitIntType(EZParser.IntTypeContext ctx) {
		this.lastDeclType = Type.INT_TYPE;
		return NO_TYPE;
	}

	// Visita a regra type_spec: REAL
	@Override
	public Type visitRealType(EZParser.RealTypeContext ctx) {
		this.lastDeclType = Type.REAL_TYPE;
		return NO_TYPE;
    }

	// Visita a regra type_spec: STRING
	@Override
	public Type visitStrType(EZParser.StrTypeContext ctx) {
		this.lastDeclType = Type.STR_TYPE;
		return NO_TYPE;
	}

    // Visita a regra var_decl: type_spec ID SEMI
    @Override
    public Type visitVar_decl(EZParser.Var_declContext ctx) {
    	// Visita a declaração de tipo para definir a variável lastDeclType.
    	visit(ctx.type_spec());
    	// Agora testa se a variável foi redeclarada.
    	newVar(ctx.ID().getSymbol());
    	return NO_TYPE;
    }

    // Visita a regra assign_stmt: ID ASSIGN expr SEMI
	@Override
	public Type visitAssign_stmt(Assign_stmtContext ctx) {
		// Visita recursivamente a expressão da direita para procurar erros.
		Type exprType = visit(ctx.expr());
		// Verifica se a variável a ser atribuída foi declarada.
		Token idToken = ctx.ID().getSymbol();
		Type idType = checkVar(idToken);
		checkAssign(idToken.getLine(), idType, exprType);
		return NO_TYPE;
	}

	// Visita a regra if_stmt: IF expr THEN stmt+ (ELSE stmt+)? END
	@Override
	public Type visitIf_stmt(If_stmtContext ctx) {
		// Visita recursivamente a expressão de teste para ver se
		// ela tem o tipo Booleano.
		Type exprType = visit(ctx.expr());
		checkBoolExpr(ctx.IF().getSymbol().getLine(), "if", exprType);
		return NO_TYPE;
	}

	// Visita a regra read_stmt: READ ID SEMI
	@Override
	public Type visitRead_stmt(Read_stmtContext ctx) {
		// Verifica se a variável que vai receber o valor lido foi declarada.
		checkVar(ctx.ID().getSymbol());
		return NO_TYPE;
	}

	// Visita a regra repeat-stmt: REPEAT stmt-list UNTIL expr
	@Override
	public Type visitRepeat_stmt(Repeat_stmtContext ctx) {
		// Visita recursivamente a expressão de teste para ver se
		// ela tem o tipo Booleano.
		Type exprType = visit(ctx.expr());
		checkBoolExpr(ctx.UNTIL().getSymbol().getLine(), "repeat", exprType);
		return NO_TYPE;
	}

	// Visita a regra expr: expr op=(TIMES | OVER) expr
	@Override
	public Type visitTimesOver(TimesOverContext ctx) {
		// Visita recursivamente as expressões da esquerda e direita
		// para determinar os seus tipos.
		Type l = visit(ctx.expr(0));
		Type r = visit(ctx.expr(1));
		if (l == NO_TYPE || r == NO_TYPE) {
			return NO_TYPE;
		}
		// Unifica os tipos para saber o tipo final da expressão.
		Type unif = l.unifyOtherArith(r);
		if (unif == NO_TYPE) {
			typeError(ctx.op.getLine(), ctx.op.getText(), l, r);
		}
		// Retorna o tipo unificado para que ele possa ser usado na
		// volta da visita dos nós.
		return unif;
	}

	// Visita a regra expr: expr op=(PLUS | MINUS) expr
	@Override
	public Type visitPlusMinus(PlusMinusContext ctx) {
		Type l = visit(ctx.expr(0));
		Type r = visit(ctx.expr(1));
		if (l == NO_TYPE || r == NO_TYPE) {
			return NO_TYPE;
		}
		Type unif;
		// Aqui precisamos diferenciar entre '+' e '-',
		// por isso que a regra na gramática associa o nome 'op' ao
		// operador.
		if (ctx.op.getType() == EZParser.PLUS) {
			unif = l.unifyPlus(r);
		} else {
			unif = l.unifyOtherArith(r);
		}
		if (unif == NO_TYPE) {
			typeError(ctx.op.getLine(), ctx.op.getText(), l, r);
		}
		return unif;
	}

	// Visita a regra expr: expr op=(EQ | LT) expr
	@Override
	public Type visitEqLt(EqLtContext ctx) {
		Type l = visit(ctx.expr(0));
		Type r = visit(ctx.expr(1));
		if (l == NO_TYPE || r == NO_TYPE) {
			return NO_TYPE;
		}
		Type unif = l.unifyComp(r);
		if (unif == NO_TYPE) {
			typeError(ctx.op.getLine(), ctx.op.getText(), l, r);
		}
		return unif;
	}

	// Visita a regra expr: LPAR expr RPAR
	@Override
	public Type visitExprPar(ExprParContext ctx) {
		// Propaga o tipo da expressão entre parênteses para cima.
		return visit(ctx.expr());
	}

	// Visita a regra expr: TRUE
	@Override
	public Type visitExprTrue(ExprTrueContext ctx) {
		return BOOL_TYPE;
	}

	// Visita a regra expr: FALSE
	@Override
	public Type visitExprFalse(ExprFalseContext ctx) {
		return BOOL_TYPE;
	}

	// Visita a regra expr: INT_VAL
	@Override
	public Type visitExprIntVal(ExprIntValContext ctx) {
		return INT_TYPE;
	}

	// Visita a regra expr: REAL_VAL
	@Override
	public Type visitExprRealVal(ExprRealValContext ctx) {
		return REAL_TYPE;
	}

	@Override
	// Visita a regra expr: STR_VAL
	public Type visitExprStrVal(ExprStrValContext ctx) {
		// Adiciona a string na tabela de strings.
		st.add(ctx.STR_VAL().getText());
		return STR_TYPE;
	}

	@Override
	// Visita a regra expr: ID
	public Type visitExprId(ExprIdContext ctx) {
		// Verifica se a variável usada na expressão foi declarada.
		return checkVar(ctx.ID().getSymbol());
	}

}

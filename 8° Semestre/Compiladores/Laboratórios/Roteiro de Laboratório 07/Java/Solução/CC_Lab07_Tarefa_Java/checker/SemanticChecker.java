package checker;

import static ast.NodeKind.ASSIGN_NODE;
import static ast.NodeKind.BLOCK_NODE;
import static ast.NodeKind.BOOL_VAL_NODE;
import static ast.NodeKind.EQ_NODE;
import static ast.NodeKind.IF_NODE;
import static ast.NodeKind.INT_VAL_NODE;
import static ast.NodeKind.LT_NODE;
import static ast.NodeKind.MINUS_NODE;
import static ast.NodeKind.OVER_NODE;
import static ast.NodeKind.PLUS_NODE;
import static ast.NodeKind.PROGRAM_NODE;
import static ast.NodeKind.READ_NODE;
import static ast.NodeKind.REAL_VAL_NODE;
import static ast.NodeKind.REPEAT_NODE;
import static ast.NodeKind.STR_VAL_NODE;
import static ast.NodeKind.TIMES_NODE;
import static ast.NodeKind.VAR_DECL_NODE;
import static ast.NodeKind.VAR_LIST_NODE;
import static ast.NodeKind.VAR_USE_NODE;
import static ast.NodeKind.WRITE_NODE;
import static typing.Conv.I2R;
import static typing.Type.BOOL_TYPE;
import static typing.Type.INT_TYPE;
import static typing.Type.NO_TYPE;
import static typing.Type.REAL_TYPE;
import static typing.Type.STR_TYPE;

import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.tree.TerminalNode;

import ast.AST;
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
import parser.EZParser.ProgramContext;
import parser.EZParser.Read_stmtContext;
import parser.EZParser.Repeat_stmtContext;
import parser.EZParser.StmtContext;
import parser.EZParser.Stmt_sectContext;
import parser.EZParser.TimesOverContext;
import parser.EZParser.Vars_sectContext;
import parser.EZParser.Write_stmtContext;
import parser.EZParserBaseVisitor;
import tables.StrTable;
import tables.VarTable;
import typing.Conv;
import typing.Conv.Unif;
import typing.Type;

/*
 * Analisador sem??ntico de EZLang implementado como um visitor
 * da ParseTree do ANTLR. A classe EZParserBaseVisitor ?? gerada
 * automaticamente e j?? possui m??todos padr??o aonde o comportamento
 * ?? s?? visitar todos os filhos. Por conta disto, basta sobreescrever
 * os m??todos que a gente quer alterar. Neste caso, todos foram sobreescritos.
 *
 * No laborat??rio anterior, foi usado Type no tipo gen??rico do
 * EZParserBaseVisitor porque a gente s?? estava fazendo uma verifica????o
 * simples dos tipos primitivos. Agora o tipo declarado ?? AST, pois o
 * analisador sem??ntico tamb??m realiza a constru????o da AST na mesma passada.
 * Assim, se a an??lise sem??ntica (uso de vari??veis e tipos) terminar sem erros,
 * ent??o temos no final uma AST que representa o programa de entrada.
 * Em linguagens mais complexas ?? prov??vel que sejam necess??rias mais passadas,
 * por exemplo, uma para an??lise sem??ntica e outra para a constru????o da AST.
 * Neste caso, talvez voc?? tenha de implementar dois visitadores diferentes.
 *
 * Lembre que o caminhamento pela Parse Tree ?? top-down. Assim, ?? preciso sempre
 * visitar os filhos de um n?? primeiro para construir as sub??rvores dos filhos.
 * No Bison isso j?? acontecia automaticamente porque o parsing l?? ?? bottom-up e
 * as a????es sem??nticas do parser j?? faziam a constru????o da AST junto com a an??lise
 * sint??tica. Aqui, ?? o inverso, por isso temos que visitar os filhos primeiro.
 */
public class SemanticChecker extends EZParserBaseVisitor<AST> {

	public final StrTable st = new StrTable();   // Tabela de strings.
    public final VarTable vt = new VarTable();   // Tabela de vari??veis.

    Type lastDeclType;  // Vari??vel "global" com o ??ltimo tipo declarado.

    private AST root; // N?? raiz da AST sendo constru??da.

    // Testa se o dado token foi declarado antes.
    // Se sim, cria e retorna um n?? de 'var use'.
    AST checkVar(Token token) {
    	String text = token.getText();
    	int line = token.getLine();
   		int idx = vt.lookupVar(text);
    	if (idx == -1) {
    		System.err.printf("SEMANTIC ERROR (%d): variable '%s' was not declared.\n", line, text);
    		System.exit(1);
            return null; // Never reached.
        }
    	return new AST(VAR_USE_NODE, idx, vt.getType(idx));
    }

    // Cria uma nova vari??vel a partir do dado token.
    // Retorna um n?? do tipo 'var declaration'.
    AST newVar(Token token) {
    	String text = token.getText();
    	int line = token.getLine();
   		int idx = vt.lookupVar(text);
        if (idx != -1) {
        	System.err.printf("SEMANTIC ERROR (%d): variable '%s' already declared at line %d.\n", line, text, vt.getLine(idx));
        	System.exit(1);
            return null; // Never reached.
        }
        idx = vt.addVar(text, line, lastDeclType);
        return new AST(VAR_DECL_NODE, idx, lastDeclType);
    }

    // ----------------------------------------------------------------------------
    // Type checking and inference.

    private static void typeError(int lineNo, String op, Type t1, Type t2) {
    	System.out.printf("SEMANTIC ERROR (%d): incompatible types for operator '%s', LHS is '%s' and RHS is '%s'.\n",
    			lineNo, op, t1.toString(), t2.toString());
    	System.exit(1);
    }

    private static void checkBoolExpr(int lineNo, String cmd, Type t) {
        if (t != BOOL_TYPE) {
            System.out.printf("SEMANTIC ERROR (%d): conditional expression in '%s' is '%s' instead of '%s'.\n",
               lineNo, cmd, t.toString(), BOOL_TYPE.toString());
            System.exit(1);
        }
    }

    // ----------------------------------------------------------------------------

    // Exibe o conte??do das tabelas em stdout.
    public void printTables() {
        System.out.print("\n\n");
        System.out.print(st);
        System.out.print("\n\n");
    	System.out.print(vt);
    	System.out.print("\n\n");
    }

    // Exibe a AST no formato DOT em stderr.
    public void printAST() {
    	AST.printDot(root, vt);
    }

    // Retorna a AST constru??da ao final da an??lise.
    public AST getAST() {
    	return this.root;
    }

    // ----------------------------------------------------------------------------
    // Visitadores.

    // Visita a regra program: PROGRAM ID SEMI vars_sect stmt_sect
    @Override
	public AST visitProgram(ProgramContext ctx) {
    	// Visita recursivamente os filhos para construir a AST.
    	AST varsSect = visit(ctx.vars_sect());
    	AST stmtSect = visit(ctx.stmt_sect());
    	// Como esta ?? a regra inicial, chegamos na raiz da AST.
    	this.root = AST.newSubtree(PROGRAM_NODE, NO_TYPE, varsSect, stmtSect);
		return this.root;
	}

    // Visita a regra vars_sect: VAR var_decl*
    @Override
	public AST visitVars_sect(Vars_sectContext ctx) {
    	// Para facilitar, sempre crio um n?? com a lista das vari??veis.
    	// Assim, n??o precisa ficar testando depois se ele existe ou n??o.
    	// Se n??o houverem vari??veis declaradas, o n?? fica sem filhos.
    	AST node = AST.newSubtree(VAR_LIST_NODE, NO_TYPE);
    	// No caso de n??o-terminais com fechos (* ou +), a chamada do m??todo
    	// correspondente retorna uma lista com todos os elementos da Parse
    	// Tree que entraram no fecho. Assim, podemos percorrer (visitar) a
    	// lista para construir as sub??rvores dos filhos.
    	// Tamb??m ?? poss??vel usar o iterador da lista aqui mas prefiro esse
    	// estilo de loop cl??ssico...
    	for (int i = 0; i < ctx.var_decl().size(); i++) {
    		AST child = visit(ctx.var_decl(i));
    		node.addChild(child);
    	}
    	return node;
	}

	// Visita a regra type_spec: BOOL
    @Override
    public AST visitBoolType(EZParser.BoolTypeContext ctx) {
    	this.lastDeclType = Type.BOOL_TYPE;
    	// N??o tem problema retornar null aqui porque o m??todo chamador
    	// ignora o valor de retorno.
    	return null;
    }

	// Visita a regra type_spec: INT
	@Override
	public AST visitIntType(EZParser.IntTypeContext ctx) {
		this.lastDeclType = Type.INT_TYPE;
		// N??o tem problema retornar null aqui porque o m??todo chamador
    	// ignora o valor de retorno.
		return null;
	}

	// Visita a regra type_spec: REAL
	@Override
	public AST visitRealType(EZParser.RealTypeContext ctx) {
		this.lastDeclType = Type.REAL_TYPE;
		// N??o tem problema retornar null aqui porque o m??todo chamador
    	// ignora o valor de retorno.
		return null;
    }

	// Visita a regra type_spec: STRING
	@Override
	public AST visitStrType(EZParser.StrTypeContext ctx) {
		this.lastDeclType = Type.STR_TYPE;
		// N??o tem problema retornar null aqui porque o m??todo chamador
    	// ignora o valor de retorno.
		return null;
	}

    // Visita a regra var_decl: type_spec ID SEMI
    @Override
    public AST visitVar_decl(EZParser.Var_declContext ctx) {
    	// Visita a defini????o do tipo da vari??vel.
    	visit(ctx.type_spec());
    	// Cria e retorna um n?? para a vari??vel.
    	return newVar(ctx.ID().getSymbol());
    }

    // Visita a regra stmt_sect: BEGIN stmt+ END
    @Override
	public AST visitStmt_sect(Stmt_sectContext ctx) {
    	// Valem os mesmos coment??rios de visitVars_sect.
    	AST node = AST.newSubtree(BLOCK_NODE, NO_TYPE);
    	for (int i = 0; i < ctx.stmt().size(); i++) {
    		AST child = visit(ctx.stmt(i));
    		node.addChild(child);
    	}
    	return node;
	}

    // Visita a regra stmt para todos os poss??veis tipos.
    // Esse m??todo n??o precisava ser sobreescrito, mas era o ??nico
    // que ficou faltando... :P
	@Override
	public AST visitStmt(StmtContext ctx) {
		return super.visitStmt(ctx);
	}

	// Visita a regra assign_stmt: ID ASSIGN expr SEMI
	@Override
	public AST visitAssign_stmt(Assign_stmtContext ctx) {
		// Visita a express??o da direita.
		AST exprNode = visit(ctx.expr());
		// Visita o identificador da esquerda.
		Token idToken = ctx.ID().getSymbol();
		AST idNode = checkVar(idToken);
		// Faz as verifica????es de tipos.
		return checkAssign(idToken.getLine(), idNode, exprNode);
	}

	// M??todo auxiliar criado s?? para separar melhor a parte de visitador
	// da parte de an??lise sem??ntica.
    private static AST checkAssign(int lineNo, AST l, AST r) {
    	Type lt = l.type;
    	Type rt = r.type;

        if (lt == BOOL_TYPE && rt != BOOL_TYPE) typeError(lineNo, ":=", lt, rt);
        if (lt == STR_TYPE  && rt != STR_TYPE)  typeError(lineNo, ":=", lt, rt);
        if (lt == INT_TYPE  && rt != INT_TYPE)  typeError(lineNo, ":=", lt, rt);

        if (lt == REAL_TYPE) {
        	if (rt == INT_TYPE) {
        		r = Conv.createConvNode(I2R, r);
        	} else if (rt != REAL_TYPE) {
        		typeError(lineNo, ":=", lt, rt);
            }
        }

        return AST.newSubtree(ASSIGN_NODE, NO_TYPE, l, r);
    }

	// Visita a regra if_stmt: IF expr THEN stmt+ (ELSE stmt+)? END
	@Override
	public AST visitIf_stmt(If_stmtContext ctx) {
		// Esse ?? o m??todo mais complicado da AST. A complica????o surge
		// principalmente porque o bloco de ELSE ?? opcional, e por conta
		// dos dois fechos 'stmt+', pois o ANTLR n??o faz distin????o entre eles.
		// Assim, comandos dos blocos de THEN e ELSE ficam todos na mesma
		// lista de 'stmt'. Pelo menos eles ficam em ordem.

		// Uma forma mais simples de resolver esse problema seria criar
		// dois novos n??o-terminais como
		// then_part: stmt+
		// else_part: stmt+
		// Assim, daria para identificar e usar as partes com m??todos diferentes.

		// Preferi n??o fazer desse jeito porque acho que voc??s v??o ter casos
		// parecidos nas gram??ticas, e assim d?? para aproveitar e mostar um pouco
		// da magia negra que d?? para fazer com o ANTLR... :P

		// Analisa a express??o booleana.
		AST exprNode = visit(ctx.expr());
		checkBoolExpr(ctx.IF().getSymbol().getLine(), "if", exprNode.type);

		// Vamos dividir o c??digo em duas partes, um IF sem ou com ELSE.
		// Para saber se um s??mbolo opcional est?? presente, basta chamar o
		// seu m??todo. Se for retornado nulo, o s??mbolo n??o existe.
		if (ctx.ELSE() == null) {
			// Caso em que n??o existe um bloco de ELSE. A?? fica simples
			// porque todos os comandos pertencem ao bloco do THEN.
			AST thenNode = AST.newSubtree(BLOCK_NODE, NO_TYPE);
			for (int i = 0; i < ctx.stmt().size(); i++) {
	    		AST child = visit(ctx.stmt(i));
	    		thenNode.addChild(child);
			}
			return AST.newSubtree(IF_NODE, NO_TYPE, exprNode, thenNode);
		} else {
			// Caso em que existe um bloco de ELSE. A?? precisamos separar
			// os 'stmt' entre os blocos de THEN e ELSE. Vamos usar o
			// Token do ELSE para fazer essa separa????o. Mas para isso
			// precisamos identificar o ??ndice do ELSE na lista de todos
			// os filhos da Parse Tree.

			// Faz uma busca pelo token na lista de filhos.
			TerminalNode elseToken = ctx.ELSE();
			int elseIdx = -1;
			for (int i = 0; i < ctx.children.size(); i++) {
				if (ctx.children.get(i).equals(elseToken)) {
					elseIdx = i;
					break;
				}
			}

			// Temos que elseIdx ?? o ??ndice na lista de todos os filhos.
			// Por outro lado, a lista de 'stmts' come??a do ??ndice zero.
			// O offset entre as duas listas ?? 3 porque a regra come??a com
			// IF expr THEN
			// ou seja, h?? 3 s??mbolos antes do primeiro bloco de 'stmt+'.
			int thenEnd = elseIdx - 3;

			// Cria o n?? com o bloco de comandos do THEN.
			AST thenNode = AST.newSubtree(BLOCK_NODE, NO_TYPE);
			for (int i = 0; i < thenEnd; i++) {
	    		AST child = visit(ctx.stmt(i));
	    		thenNode.addChild(child);
			}

			// Cria o n?? com o bloco de comandos do ELSE.
			AST elseNode = AST.newSubtree(BLOCK_NODE, NO_TYPE);
			for (int i = thenEnd; i < ctx.stmt().size(); i++) {
	    		AST child = visit(ctx.stmt(i));
	    		elseNode.addChild(child);
			}

			return AST.newSubtree(IF_NODE, NO_TYPE, exprNode, thenNode, elseNode);
		}
	}

	// Visita a regra read_stmt: READ ID SEMI
	@Override
	public AST visitRead_stmt(Read_stmtContext ctx) {
		AST idNode = checkVar(ctx.ID().getSymbol());
		return AST.newSubtree(READ_NODE, NO_TYPE, idNode);
	}

	// Visita a regra repeat_stmt: REPEAT stmt+ UNTIL expr
	@Override
	public AST visitRepeat_stmt(Repeat_stmtContext ctx) {
		// Analisa a express??o booleana.
		AST exprNode = visit(ctx.expr());
		checkBoolExpr(ctx.UNTIL().getSymbol().getLine(), "repeat", exprNode.type);

		// Constr??i o bloco de c??digo do loop.
		AST blockNode = AST.newSubtree(BLOCK_NODE, NO_TYPE);
    	for (int i = 0; i < ctx.stmt().size(); i++) {
    		AST child = visit(ctx.stmt(i));
    		blockNode.addChild(child);
    	}

    	return AST.newSubtree(REPEAT_NODE, NO_TYPE, blockNode, exprNode);
	}

	// Visita a regra write_stmt: WRITE expr SEMI
	@Override
	public AST visitWrite_stmt(Write_stmtContext ctx) {
		AST exprNode = visit(ctx.expr());
		return AST.newSubtree(WRITE_NODE, NO_TYPE, exprNode);
	}

	// Visita a regra expr: expr op=(TIMES | OVER) expr
	@Override
	public AST visitTimesOver(TimesOverContext ctx) {
		// Visita recursivamente as duas subexpress??es.
		AST l = visit(ctx.expr(0));
		AST r = visit(ctx.expr(1));

		// Faz a unifica????o dos tipos para determinar o tipo resultante.
		Type lt = l.type;
		Type rt = r.type;
		Unif unif = lt.unifyOtherArith(rt);

		if (unif.type == NO_TYPE) {
			typeError(ctx.op.getLine(), ctx.op.getText(), lt, rt);
		}

		// Cria os n??s de convers??o que forem necess??rios segundo a
		// estrutura de convers??o.
		l = Conv.createConvNode(unif.lc, l);
		r = Conv.createConvNode(unif.rc, r);

		// Olha qual ?? o operador e cria o n?? correspondente na AST.
		if (ctx.op.getType() == EZParser.TIMES) {
			return AST.newSubtree(TIMES_NODE, unif.type, l, r);
		} else { // OVER
			return AST.newSubtree(OVER_NODE, unif.type, l, r);
		}
	}

	// Visita a regra expr: expr op=(PLUS | MINUS) expr
	@Override
	public AST visitPlusMinus(PlusMinusContext ctx) {
		// Visita recursivamente as duas subexpress??es.
		AST l = visit(ctx.expr(0));
		AST r = visit(ctx.expr(1));

		// Faz a unifica????o dos tipos para determinar o tipo resultante.
		Type lt = l.type;
		Type rt = r.type;
		Unif unif;
		// ?? preciso diferenciar '+' e '-' na unifica????o por conta da sem??ntica.
		if (ctx.op.getType() == EZParser.PLUS) {
			unif = lt.unifyPlus(rt);
		} else {
			unif = lt.unifyOtherArith(rt);
		}

		if (unif.type == NO_TYPE) {
			typeError(ctx.op.getLine(), ctx.op.getText(), lt, rt);
		}

		// Cria os n??s de convers??o que forem necess??rios segundo a
		// estrutura de convers??o.
		l = Conv.createConvNode(unif.lc, l);
		r = Conv.createConvNode(unif.rc, r);

		// Olha qual ?? o operador e cria o n?? correspondente na AST.
		if (ctx.op.getType() == EZParser.PLUS) {
			return AST.newSubtree(PLUS_NODE, unif.type, l, r);
		} else { // MINUS
			return AST.newSubtree(MINUS_NODE, unif.type, l, r);
		}
	}

	// Visita a regra expr: expr op=(EQ | LT) expr
	@Override
	public AST visitEqLt(EqLtContext ctx) {
		// Visita recursivamente as duas subexpress??es.
		AST l = visit(ctx.expr(0));
		AST r = visit(ctx.expr(1));

		// Faz a unifica????o dos tipos para determinar o tipo resultante.
		Type lt = l.type;
		Type rt = r.type;
		Unif unif = lt.unifyComp(rt);

		if (unif.type == NO_TYPE) {
			typeError(ctx.op.getLine(), ctx.op.getText(), lt, rt);
		}

		// Cria os n??s de convers??o que forem necess??rios segundo a
		// estrutura de convers??o.
		l = Conv.createConvNode(unif.lc, l);
		r = Conv.createConvNode(unif.rc, r);

		// Olha qual ?? o operador e cria o n?? correspondente na AST.
		if (ctx.op.getType() == EZParser.EQ) {
			return AST.newSubtree(EQ_NODE, unif.type, l, r);
		} else { // LT
			return AST.newSubtree(LT_NODE, unif.type, l, r);
		}
	}

	// Visita a regra expr: LPAR expr RPAR
	@Override
	public AST visitExprPar(ExprParContext ctx) {
		// Propaga o n?? criado para a express??o.
		return visit(ctx.expr());
	}

	// Visita a regra expr: TRUE
	@Override
	public AST visitExprTrue(ExprTrueContext ctx) {
		// Fim da recurs??o, representa 'true' como o inteiro '1'.
		return new AST(BOOL_VAL_NODE, 1, BOOL_TYPE);
	}

	// Visita a regra expr: FALSE
	@Override
	public AST visitExprFalse(ExprFalseContext ctx) {
		// Fim da recurs??o, representa 'false' como o inteiro '0'.
		return new AST(BOOL_VAL_NODE, 0, BOOL_TYPE);
	}

	// Visita a regra expr: INT_VAL
	@Override
	public AST visitExprIntVal(ExprIntValContext ctx) {
		// Fim da recurs??o, converte o lexema da constante inteira.
		int intData = Integer.parseInt(ctx.getText());
		return new AST(INT_VAL_NODE, intData, INT_TYPE);
	}

	// Visita a regra expr: REAL_VAL
	@Override
	public AST visitExprRealVal(ExprRealValContext ctx) {
		// Fim da recurs??o, converte o lexema da constante real.
		float floatData = Float.parseFloat(ctx.getText());
		return new AST(REAL_VAL_NODE, floatData, REAL_TYPE);
	}

	@Override
	// Visita a regra expr: STR_VAL
	public AST visitExprStrVal(ExprStrValContext ctx) {
		// Adiciona a string na tabela de strings.
		int idx = st.addStr(ctx.STR_VAL().getText());
		// Campo 'data' do n?? da AST guarda o ??ndice na tabela.
		return new AST(STR_VAL_NODE, idx, STR_TYPE);
	}

	@Override
	// Visita a regra expr: ID
	public AST visitExprId(ExprIdContext ctx) {
		// Fim da recurs??o, retorna um n?? de 'var use'.
		return checkVar(ctx.ID().getSymbol());
	}

}

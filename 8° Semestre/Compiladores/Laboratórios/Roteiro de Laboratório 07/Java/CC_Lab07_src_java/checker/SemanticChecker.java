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
 * Analisador semântico de EZLang implementado como um visitor
 * da ParseTree do ANTLR. A classe EZParserBaseVisitor é gerada
 * automaticamente e já possui métodos padrão aonde o comportamento
 * é só visitar todos os filhos. Por conta disto, basta sobreescrever
 * os métodos que a gente quer alterar. Neste caso, todos foram sobreescritos.
 *
 * No laboratório anterior, foi usado Type no tipo genérico do
 * EZParserBaseVisitor porque a gente só estava fazendo uma verificação
 * simples dos tipos primitivos. Agora o tipo declarado é AST, pois o
 * analisador semântico também realiza a construção da AST na mesma passada.
 * Assim, se a análise semântica (uso de variáveis e tipos) terminar sem erros,
 * então temos no final uma AST que representa o programa de entrada.
 * Em linguagens mais complexas é provável que sejam necessárias mais passadas,
 * por exemplo, uma para análise semântica e outra para a construção da AST.
 * Neste caso, talvez você tenha de implementar dois visitadores diferentes.
 *
 * Lembre que o caminhamento pela Parse Tree é top-down. Assim, é preciso sempre
 * visitar os filhos de um nó primeiro para construir as subárvores dos filhos.
 * No Bison isso já acontecia automaticamente porque o parsing lá é bottom-up e
 * as ações semânticas do parser já faziam a construção da AST junto com a análise
 * sintática. Aqui, é o inverso, por isso temos que visitar os filhos primeiro.
 */
public class SemanticChecker extends EZParserBaseVisitor<AST> {

	public final StrTable st = new StrTable();   // Tabela de strings.
    public final VarTable vt = new VarTable();   // Tabela de variáveis.

    Type lastDeclType;  // Variável "global" com o último tipo declarado.

    private AST root; // Nó raiz da AST sendo construída.

    // Testa se o dado token foi declarado antes.
    // Se sim, cria e retorna um nó de 'var use'.
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

    // Cria uma nova variável a partir do dado token.
    // Retorna um nó do tipo 'var declaration'.
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

    // Exibe o conteúdo das tabelas em stdout.
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

    // Retorna a AST construída ao final da análise.
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
    	// Como esta é a regra inicial, chegamos na raiz da AST.
    	this.root = AST.newSubtree(PROGRAM_NODE, NO_TYPE, varsSect, stmtSect);
		return this.root;
	}

    // Visita a regra vars_sect: VAR var_decl*
    @Override
	public AST visitVars_sect(Vars_sectContext ctx) {
    	// Para facilitar, sempre crio um nó com a lista das variáveis.
    	// Assim, não precisa ficar testando depois se ele existe ou não.
    	// Se não houverem variáveis declaradas, o nó fica sem filhos.
    	AST node = AST.newSubtree(VAR_LIST_NODE, NO_TYPE);
    	// No caso de não-terminais com fechos (* ou +), a chamada do método
    	// correspondente retorna uma lista com todos os elementos da Parse
    	// Tree que entraram no fecho. Assim, podemos percorrer (visitar) a
    	// lista para construir as subárvores dos filhos.
    	// Também é possível usar o iterador da lista aqui mas prefiro esse
    	// estilo de loop clássico...
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
    	// Não tem problema retornar null aqui porque o método chamador
    	// ignora o valor de retorno.
    	return null;
    }

	// Visita a regra type_spec: INT
	@Override
	public AST visitIntType(EZParser.IntTypeContext ctx) {
		this.lastDeclType = Type.INT_TYPE;
		// Não tem problema retornar null aqui porque o método chamador
    	// ignora o valor de retorno.
		return null;
	}

	// Visita a regra type_spec: REAL
	@Override
	public AST visitRealType(EZParser.RealTypeContext ctx) {
		this.lastDeclType = Type.REAL_TYPE;
		// Não tem problema retornar null aqui porque o método chamador
    	// ignora o valor de retorno.
		return null;
    }

	// Visita a regra type_spec: STRING
	@Override
	public AST visitStrType(EZParser.StrTypeContext ctx) {
		this.lastDeclType = Type.STR_TYPE;
		// Não tem problema retornar null aqui porque o método chamador
    	// ignora o valor de retorno.
		return null;
	}

    // Visita a regra var_decl: type_spec ID SEMI
    @Override
    public AST visitVar_decl(EZParser.Var_declContext ctx) {
    	// Visita a definição do tipo da variável.
    	visit(ctx.type_spec());
    	// Cria e retorna um nó para a variável.
    	return newVar(ctx.ID().getSymbol());
    }

    // Visita a regra stmt_sect: BEGIN stmt+ END
    @Override
	public AST visitStmt_sect(Stmt_sectContext ctx) {
    	// Valem os mesmos comentários de visitVars_sect.
    	AST node = AST.newSubtree(BLOCK_NODE, NO_TYPE);
    	for (int i = 0; i < ctx.stmt().size(); i++) {
    		AST child = visit(ctx.stmt(i));
    		node.addChild(child);
    	}
    	return node;
	}

    // Visita a regra stmt para todos os possíveis tipos.
    // Esse método não precisava ser sobreescrito, mas era o único
    // que ficou faltando... :P
	@Override
	public AST visitStmt(StmtContext ctx) {
		return super.visitStmt(ctx);
	}

	// Visita a regra assign_stmt: ID ASSIGN expr SEMI
	@Override
	public AST visitAssign_stmt(Assign_stmtContext ctx) {
		// Visita a expressão da direita.
		AST exprNode = visit(ctx.expr());
		// Visita o identificador da esquerda.
		Token idToken = ctx.ID().getSymbol();
		AST idNode = checkVar(idToken);
		// Faz as verificações de tipos.
		return checkAssign(idToken.getLine(), idNode, exprNode);
	}

	// Método auxiliar criado só para separar melhor a parte de visitador
	// da parte de análise semântica.
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
		// Esse é o método mais complicado da AST. A complicação surge
		// principalmente porque o bloco de ELSE é opcional, e por conta
		// dos dois fechos 'stmt+', pois o ANTLR não faz distinção entre eles.
		// Assim, comandos dos blocos de THEN e ELSE ficam todos na mesma
		// lista de 'stmt'. Pelo menos eles ficam em ordem.

		// Uma forma mais simples de resolver esse problema seria criar
		// dois novos não-terminais como
		// then_part: stmt+
		// else_part: stmt+
		// Assim, daria para identificar e usar as partes com métodos diferentes.

		// Preferi não fazer desse jeito porque acho que vocês vão ter casos
		// parecidos nas gramáticas, e assim dá para aproveitar e mostar um pouco
		// da magia negra que dá para fazer com o ANTLR... :P

		// Analisa a expressão booleana.
		AST exprNode = visit(ctx.expr());
		checkBoolExpr(ctx.IF().getSymbol().getLine(), "if", exprNode.type);

		// Vamos dividir o código em duas partes, um IF sem ou com ELSE.
		// Para saber se um símbolo opcional está presente, basta chamar o
		// seu método. Se for retornado nulo, o símbolo não existe.
		if (ctx.ELSE() == null) {
			// Caso em que não existe um bloco de ELSE. Aí fica simples
			// porque todos os comandos pertencem ao bloco do THEN.
			AST thenNode = AST.newSubtree(BLOCK_NODE, NO_TYPE);
			for (int i = 0; i < ctx.stmt().size(); i++) {
	    		AST child = visit(ctx.stmt(i));
	    		thenNode.addChild(child);
			}
			return AST.newSubtree(IF_NODE, NO_TYPE, exprNode, thenNode);
		} else {
			// Caso em que existe um bloco de ELSE. Aí precisamos separar
			// os 'stmt' entre os blocos de THEN e ELSE. Vamos usar o
			// Token do ELSE para fazer essa separação. Mas para isso
			// precisamos identificar o índice do ELSE na lista de todos
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

			// Temos que elseIdx é o índice na lista de todos os filhos.
			// Por outro lado, a lista de 'stmts' começa do índice zero.
			// O offset entre as duas listas é 3 porque a regra começa com
			// IF expr THEN
			// ou seja, há 3 símbolos antes do primeiro bloco de 'stmt+'.
			int thenEnd = elseIdx - 3;

			// Cria o nó com o bloco de comandos do THEN.
			AST thenNode = AST.newSubtree(BLOCK_NODE, NO_TYPE);
			for (int i = 0; i < thenEnd; i++) {
	    		AST child = visit(ctx.stmt(i));
	    		thenNode.addChild(child);
			}

			// Cria o nó com o bloco de comandos do ELSE.
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
		// Analisa a expressão booleana.
		AST exprNode = visit(ctx.expr());
		checkBoolExpr(ctx.UNTIL().getSymbol().getLine(), "repeat", exprNode.type);

		// Constrói o bloco de código do loop.
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
		// Visita recursivamente as duas subexpressões.
		AST l = visit(ctx.expr(0));
		AST r = visit(ctx.expr(1));

		// Faz a unificação dos tipos para determinar o tipo resultante.
		Type lt = l.type;
		Type rt = r.type;
		Unif unif = lt.unifyOtherArith(rt);

		if (unif.type == NO_TYPE) {
			typeError(ctx.op.getLine(), ctx.op.getText(), lt, rt);
		}

		// Cria os nós de conversão que forem necessários segundo a
		// estrutura de conversão.
		l = Conv.createConvNode(unif.lc, l);
		r = Conv.createConvNode(unif.rc, r);

		// Olha qual é o operador e cria o nó correspondente na AST.
		if (ctx.op.getType() == EZParser.TIMES) {
			return AST.newSubtree(TIMES_NODE, unif.type, l, r);
		} else { // OVER
			return AST.newSubtree(OVER_NODE, unif.type, l, r);
		}
	}

	// Visita a regra expr: expr op=(PLUS | MINUS) expr
	@Override
	public AST visitPlusMinus(PlusMinusContext ctx) {
		// Visita recursivamente as duas subexpressões.
		AST l = visit(ctx.expr(0));
		AST r = visit(ctx.expr(1));

		// Faz a unificação dos tipos para determinar o tipo resultante.
		Type lt = l.type;
		Type rt = r.type;
		Unif unif;
		// É preciso diferenciar '+' e '-' na unificação por conta da semântica.
		if (ctx.op.getType() == EZParser.PLUS) {
			unif = lt.unifyPlus(rt);
		} else {
			unif = lt.unifyOtherArith(rt);
		}

		if (unif.type == NO_TYPE) {
			typeError(ctx.op.getLine(), ctx.op.getText(), lt, rt);
		}

		// Cria os nós de conversão que forem necessários segundo a
		// estrutura de conversão.
		l = Conv.createConvNode(unif.lc, l);
		r = Conv.createConvNode(unif.rc, r);

		// Olha qual é o operador e cria o nó correspondente na AST.
		if (ctx.op.getType() == EZParser.PLUS) {
			return AST.newSubtree(PLUS_NODE, unif.type, l, r);
		} else { // MINUS
			return AST.newSubtree(MINUS_NODE, unif.type, l, r);
		}
	}

	// Visita a regra expr: expr op=(EQ | LT) expr
	@Override
	public AST visitEqLt(EqLtContext ctx) {
		// Visita recursivamente as duas subexpressões.
		AST l = visit(ctx.expr(0));
		AST r = visit(ctx.expr(1));

		// Faz a unificação dos tipos para determinar o tipo resultante.
		Type lt = l.type;
		Type rt = r.type;
		Unif unif = lt.unifyComp(rt);

		if (unif.type == NO_TYPE) {
			typeError(ctx.op.getLine(), ctx.op.getText(), lt, rt);
		}

		// Cria os nós de conversão que forem necessários segundo a
		// estrutura de conversão.
		l = Conv.createConvNode(unif.lc, l);
		r = Conv.createConvNode(unif.rc, r);

		// Olha qual é o operador e cria o nó correspondente na AST.
		if (ctx.op.getType() == EZParser.EQ) {
			return AST.newSubtree(EQ_NODE, unif.type, l, r);
		} else { // LT
			return AST.newSubtree(LT_NODE, unif.type, l, r);
		}
	}

	// Visita a regra expr: LPAR expr RPAR
	@Override
	public AST visitExprPar(ExprParContext ctx) {
		// Propaga o nó criado para a expressão.
		return visit(ctx.expr());
	}

	// Visita a regra expr: TRUE
	@Override
	public AST visitExprTrue(ExprTrueContext ctx) {
		// Fim da recursão, representa 'true' como o inteiro '1'.
		return new AST(BOOL_VAL_NODE, 1, BOOL_TYPE);
	}

	// Visita a regra expr: FALSE
	@Override
	public AST visitExprFalse(ExprFalseContext ctx) {
		// Fim da recursão, representa 'false' como o inteiro '0'.
		return new AST(BOOL_VAL_NODE, 0, BOOL_TYPE);
	}

	// Visita a regra expr: INT_VAL
	@Override
	public AST visitExprIntVal(ExprIntValContext ctx) {
		// Fim da recursão, converte o lexema da constante inteira.
		int intData = Integer.parseInt(ctx.getText());
		return new AST(INT_VAL_NODE, intData, INT_TYPE);
	}

	// Visita a regra expr: REAL_VAL
	@Override
	public AST visitExprRealVal(ExprRealValContext ctx) {
		// Fim da recursão, converte o lexema da constante real.
		float floatData = Float.parseFloat(ctx.getText());
		return new AST(REAL_VAL_NODE, floatData, REAL_TYPE);
	}

	@Override
	// Visita a regra expr: STR_VAL
	public AST visitExprStrVal(ExprStrValContext ctx) {
		// Adiciona a string na tabela de strings.
		int idx = st.addStr(ctx.STR_VAL().getText());
		// Campo 'data' do nó da AST guarda o índice na tabela.
		return new AST(STR_VAL_NODE, idx, STR_TYPE);
	}

	@Override
	// Visita a regra expr: ID
	public AST visitExprId(ExprIdContext ctx) {
		// Fim da recursão, retorna um nó de 'var use'.
		return checkVar(ctx.ID().getSymbol());
	}

}

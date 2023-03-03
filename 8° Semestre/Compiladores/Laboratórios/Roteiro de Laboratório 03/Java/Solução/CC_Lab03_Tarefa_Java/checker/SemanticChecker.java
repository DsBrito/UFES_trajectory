package checker;

import org.antlr.v4.runtime.Token;

import parser.EZParser;
import parser.EZParser.Assign_stmtContext;
import parser.EZParser.ExprIdContext;
import parser.EZParser.ExprStrValContext;
import parser.EZParser.Read_stmtContext;
import parser.EZParserBaseVisitor;
import tables.StrTable;
import tables.VarTable;
import typing.Type;

/*
 * Analisador semântico de EZLang implementado como um visitor
 * da ParseTree do ANTLR. A classe EZParserBaseVisitor é gerada
 * automaticamente e já possui métodos padrão aonde o comportamento
 * é visitar todos os filhos. Por conta disto, basta sobreescrever
 * os métodos que a gente quer alterar.
 * 
 * Por enquanto só há uma verificação simples de declaração de
 * variáveis usando uma tabela de símbolos. Funcionalidades adicionais
 * como análise de tipos serão incluídas no próximo laboratório.
 * 
 * O tipo Void indicado na super classe define o valor de retorno dos
 * métodos do visitador. Depois vamos alterar isso para poder construir
 * a AST.
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
 */
public class SemanticChecker extends EZParserBaseVisitor<Void> {

	private StrTable st = new StrTable();   // Tabela de strings.
    private VarTable vt = new VarTable();   // Tabela de variáveis.
    
    private Type lastDeclType;  // Variável "global" com o último tipo declarado.

    // Testa se o dado token foi declarado antes.
    private void checkVar(Token token) {
    	String text = token.getText();
    	int line = token.getLine();
   		int idx = vt.lookupVar(text);
    	if (idx == -1) {
    		System.err.printf("SEMANTIC ERROR (%d): variable '%s' was not declared.\n", line, text);
    		System.exit(1);
            return; // Never reached.
        }
    }
    
    // Cria uma nova variável a partir do dado token.
    private void newVar(Token token) {
    	String text = token.getText();
    	int line = token.getLine();
   		int idx = vt.lookupVar(text);
        if (idx != -1) {
        	System.err.printf("SEMANTIC ERROR (%d): variable '%s' already declared at line %d.\n", line, text, vt.getLine(idx));
        	System.exit(1);
            return; // Never reached.
        }
        vt.addVar(text, line, lastDeclType);
    }

    // Exibe o conteúdo das tabelas em stdout.
    public void printTables() {
        System.out.print("\n\n");
        System.out.print(st);
        System.out.print("\n\n");
    	System.out.print(vt);
    	System.out.print("\n\n");
    }
    
    // Visita a regra type_spec: BOOL
    // Note que esse método só foi criado pelo ANTLR porque a regra da
    // linha 29 de EZParser.g foi marcada com o identificador # boolType.
    // O mesmo vale para as demais regras de type_spec.
    @Override
    public Void visitBoolType(EZParser.BoolTypeContext ctx) {
    	this.lastDeclType = Type.BOOL_TYPE;
    	return null; // Java says must return something even when Void
    }
	
    // Visita a regra type_spec: INT
	@Override
	public Void visitIntType(EZParser.IntTypeContext ctx) {
		this.lastDeclType = Type.INT_TYPE;
		return null; // Java says must return something even when Void
	}
	
	// Visita a regra type_spec: REAL
	@Override
	public Void visitRealType(EZParser.RealTypeContext ctx) {
		this.lastDeclType = Type.REAL_TYPE;
		return null; // Java says must return something even when Void
    }
	
	// Visita a regra type_spec: STRING
	@Override
	public Void visitStrType(EZParser.StrTypeContext ctx) {
		this.lastDeclType = Type.STR_TYPE;
		return null; // Java says must return something even when Void
	}
    
    // Visita a regra var_decl: type_spec ID SEMI
    @Override
    public Void visitVar_decl(EZParser.Var_declContext ctx) {
    	// Visita a declaração de tipo para definir a variável lastDeclType.
    	visit(ctx.type_spec());
    	// Agora testa se a variável foi redeclarada.
    	newVar(ctx.ID().getSymbol());
    	return null; // Java says must return something even when Void
    }

    // Visita a regra assign_stmt: ID ASSIGN expr SEMI
	@Override
	public Void visitAssign_stmt(Assign_stmtContext ctx) {
		// Visita recursivamente a expressão da direita para procurar erros. 
		visit(ctx.expr());
		// Verifica se a variável a ser atribuída foi declarada.
		checkVar(ctx.ID().getSymbol());
		return null; // Java says must return something even when Void
	}

	// Visita a regra read_stmt: READ ID SEMI
	@Override
	public Void visitRead_stmt(Read_stmtContext ctx) {
		// Verifica se a variável que vai receber o valor lido foi declarada.
		checkVar(ctx.ID().getSymbol());
		return null; // Java says must return something even when Void
	}

	@Override
	// Visita a regra expr: STR_VAL
	// Valem os mesmos comentários do método visitBoolType.
	public Void visitExprStrVal(ExprStrValContext ctx) {
		// Adiciona a string na tabela de strings.
		st.add(ctx.STR_VAL().getText());
		return null; // Java says must return something even when Void
	}

	@Override
	// Visita a regra expr: ID
	// Valem os mesmos comentários do método visitBoolType.
	public Void visitExprId(ExprIdContext ctx) {
		// Verifica se a variável usada na expressão foi declarada.
		checkVar(ctx.ID().getSymbol());
		return null; // Java says must return something even when Void
	}
	
}

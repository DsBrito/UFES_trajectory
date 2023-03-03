package typing;

import static ast.NodeKind.B2I_NODE;
import static ast.NodeKind.B2R_NODE;
import static ast.NodeKind.B2S_NODE;
import static ast.NodeKind.I2R_NODE;
import static ast.NodeKind.I2S_NODE;
import static ast.NodeKind.R2S_NODE;

import ast.AST;

public enum Conv {
	B2I,  // Bool to Int
    B2R,  // Bool to Real
    B2S,  // Bool to String
    I2R,  // Int to Real
    I2S,  // Int to String
    R2S,  // Real to String
    NONE; // No type conversion

	// Cria e retorna um novo nó de conversão da AST segundo o parâmetro 'conv' passado.
	// O parâmetro 'n' é o nó que será pendurado como filho do nó de conversão.
	// Caso a conversão indicada seja 'NONE', a função simplesmente retorna o próprio
	// nó passado como argumento.
	public static AST createConvNode(Conv conv, AST n) {
	    switch(conv) {
	        case B2I:  return AST.newSubtree(B2I_NODE, Type.INT_TYPE, n);
	        case B2R:  return AST.newSubtree(B2R_NODE, Type.REAL_TYPE, n);
	        case B2S:  return AST.newSubtree(B2S_NODE, Type.STR_TYPE, n);
	        case I2R:  return AST.newSubtree(I2R_NODE, Type.REAL_TYPE, n);
	        case I2S:  return AST.newSubtree(I2S_NODE, Type.STR_TYPE, n);
	        case R2S:  return AST.newSubtree(R2S_NODE, Type.STR_TYPE, n);
	        case NONE: return n;
	        default:
	            System.err.printf("INTERNAL ERROR: invalid conversion of types!\n");
	            System.exit(1);
	            return null; // Never reached...
	    }
	}

	// Classe que define as informações de unificação para os tipos em expressões.
    public static final class Unif {

    	// Declarei tudo como final para não precisar de getter/setter.
    	public final Type type; // Tipo unificado
		public final Conv lc; 	// Conversão do lado esquerdo
		public final Conv rc; 	// Conversão do lado direito

		public Unif(Type type, Conv lc, Conv rc) {
			this.type = type;
			this.lc = lc;
			this.rc = rc;
		}

	}
}

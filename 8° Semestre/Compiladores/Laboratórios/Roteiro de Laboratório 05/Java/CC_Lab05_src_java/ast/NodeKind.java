package ast;

// Enumeração dos tipos de nós de uma AST.
// Adaptado da versão original em C.
// Algumas pessoas podem preferir criar uma hierarquia de herança para os
// nós para deixar o código "mais OO". Particularmente eu não sou muito
// fã, acho que só complica mais as coisas. Imagine uma classe abstrata AST
// com mais de 20 classes herdando dela, uma classe para cada tipo de nó...
public enum NodeKind {
    ASSIGN_NODE,
    EQ_NODE,
    BLOCK_NODE,
    BOOL_VAL_NODE,
    IF_NODE,
    INT_VAL_NODE,
    LT_NODE,
    MINUS_NODE,
    OVER_NODE,
    PLUS_NODE,
    PROGRAM_NODE,
    READ_NODE,
    REAL_VAL_NODE,
    REPEAT_NODE,
    STR_VAL_NODE,
    TIMES_NODE,
    VAR_DECL_NODE,
    VAR_LIST_NODE,
    VAR_USE_NODE,
    WRITE_NODE,
    // Type conversion nodes
    B2I_NODE,
    B2R_NODE,
    B2S_NODE,
    I2R_NODE,
    I2S_NODE,
    R2S_NODE;

	public String toString() {
		switch(this) {
            case ASSIGN_NODE:   return ":=";
            case EQ_NODE:       return "=";
            case BLOCK_NODE:    return "block";
            case BOOL_VAL_NODE: return "";
            case IF_NODE:       return "if";
            case INT_VAL_NODE:  return "";
            case LT_NODE:       return "<";
            case MINUS_NODE:    return "-";
            case OVER_NODE:     return "/";
            case PLUS_NODE:     return "+";
            case PROGRAM_NODE:  return "program";
            case READ_NODE:     return "read";
            case REAL_VAL_NODE: return "";
            case REPEAT_NODE:   return "repeat";
            case STR_VAL_NODE:  return "";
            case TIMES_NODE:    return "*";
            case VAR_DECL_NODE: return "var_decl";
            case VAR_LIST_NODE: return "var_list";
            case VAR_USE_NODE:  return "var_use";
            case WRITE_NODE:    return "write";
            case B2I_NODE:      return "B2I";
            case B2R_NODE:      return "B2R";
            case B2S_NODE:      return "B2S";
            case I2R_NODE:      return "I2R";
            case I2S_NODE:      return "I2S";
            case R2S_NODE:      return "R2S";
			default:
				System.err.println("ERROR: Fall through in NodeKind enumeration!");
				System.exit(1);
				return ""; // Never reached.
		}
	}

	public static boolean hasData(NodeKind kind) {
		switch(kind) {
	        case BOOL_VAL_NODE:
	        case INT_VAL_NODE:
	        case REAL_VAL_NODE:
	        case STR_VAL_NODE:
	        case VAR_DECL_NODE:
	        case VAR_USE_NODE:
	            return true;
	        default:
	            return false;
		}
	}
}

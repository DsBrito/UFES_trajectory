package typing;

// Enumeração dos tipos primitivos que podem existir em EZLang.
public enum Type {
	INT_TYPE,
    REAL_TYPE,
    BOOL_TYPE,
    STR_TYPE,
    NO_TYPE;

	public String toString() {
		switch(this) {
			case INT_TYPE:	return "int";
			case REAL_TYPE: return "real";
			case BOOL_TYPE: return "bool";
			case STR_TYPE: 	return "string";
			case NO_TYPE:   return "no_type";
			default:
				System.err.println("ERROR: Fall through in Type enumeration!");
				System.exit(1);
				return ""; // Never reached.
		}
	}

	// Tabela de unificação de tipos primitivos para o
	// operador '+'.
	private static Type plus[][] = {
		{ INT_TYPE,  REAL_TYPE, INT_TYPE,  STR_TYPE },
		{ REAL_TYPE, REAL_TYPE, REAL_TYPE, STR_TYPE },
		{ INT_TYPE,  REAL_TYPE, BOOL_TYPE, STR_TYPE },
		{ STR_TYPE,  STR_TYPE,  STR_TYPE,  STR_TYPE }
	};

	public Type unifyPlus(Type that) {
		return plus[this.ordinal()][that.ordinal()];
	}

	// Tabela de unificação de tipos primitivos para os
	// demais operadores aritméticos.
	private static Type other[][] = {
		{ INT_TYPE,  REAL_TYPE, NO_TYPE, NO_TYPE },
		{ REAL_TYPE, REAL_TYPE, NO_TYPE, NO_TYPE },
		{ NO_TYPE,   NO_TYPE,   NO_TYPE, NO_TYPE },
		{ NO_TYPE,   NO_TYPE,   NO_TYPE, NO_TYPE }
	};

	public Type unifyOtherArith(Type that) {
	    return other[this.ordinal()][that.ordinal()];
	}

	// Tabela de unificação de tipos primitivos para os
	// operadores de comparação.
	private static Type comp[][] = {
		{ BOOL_TYPE, BOOL_TYPE, NO_TYPE, NO_TYPE },
		{ BOOL_TYPE, BOOL_TYPE, NO_TYPE, NO_TYPE },
		{ NO_TYPE,   NO_TYPE,   NO_TYPE, NO_TYPE },
		{ NO_TYPE,   NO_TYPE,   NO_TYPE, BOOL_TYPE}
	};

	public Type unifyComp(Type that) {
		return comp[this.ordinal()][that.ordinal()];
	}
}

package code;

import java.util.Vector;

import tables.VarTable;

/*
 * Implementação de uma memória (vetor) de words,
 * com os métodos que facilitam acessar um valor
 * inteiro ou real.
 */
@SuppressWarnings("serial")
public class Memory extends Vector<Word> {

	// Cria a memória do tamanho das tabela de variáveis.
	// O índice na tabela é o "endereço" na memória.
	public Memory(VarTable vt) {
		for (int i = 0; i < vt.size(); i++) {
			this.add(Word.fromInt(0));
		}
	}

	// No mundo real esses métodos precisam de verificações de erros.
	
	public void storei(int addr, int value) {
		this.set(addr, Word.fromInt(value));
	}
	
	public int loadi(int addr) {
		return this.get(addr).toInt();
	}
	
	public void storef(int addr, float value) {
		this.set(addr, Word.fromFloat(value));
	}
	
	public float loadf(int addr) {
		return this.get(addr).toFloat();
	}
	
}

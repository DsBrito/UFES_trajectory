package code;

import java.util.Formatter;
import java.util.Stack;

/*
 * Implementação de uma pilha de words, com os métodos
 * que facilitam empilhar ou desempilhar um valor
 * inteiro ou real.
 */
@SuppressWarnings("serial")
public final class DataStack extends Stack<Word> {
	// No mundo real esses métodos precisam de verificações de erros.
	
	public void pushi(int value) {
		super.push(Word.fromInt(value));
	}

	public int popi() {
		return super.pop().toInt();
	}
	
	public void pushf(float value) {
		super.push(Word.fromFloat(value));
	}

	public float popf() {
		return super.pop().toFloat();
	}

	public String toString() {
		StringBuilder sb = new StringBuilder();
		Formatter f = new Formatter(sb);
		f.format("*** STACK: ");
		for (int i = 0; i < this.size(); i++) {
			f.format("%d ", this.get(i).toInt());
		}
		f.format("\n");
		f.close();
		return sb.toString();
	}
	
}

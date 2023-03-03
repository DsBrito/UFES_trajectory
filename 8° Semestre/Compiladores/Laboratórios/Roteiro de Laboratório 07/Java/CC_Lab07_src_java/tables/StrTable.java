package tables;

import java.util.ArrayList;
import java.util.Formatter;

@SuppressWarnings("serial")
public final class StrTable extends ArrayList<String> {
    // No mundo real isto certamente deveria ser um hash...

	// Claro que aqui não é adequado uma busca serial.
	// Como já tido em sala estamos interessado no uso da tabela, não na sua implementação.
	// Retorna a posição aonde a string foi inserida.
	// Não dá mais para fazer @Override do método 'add' porque agora a gente precisa retornar
	// um int e não um boolean.
    public int addStr(String s) {
    	int i;
		for (i = 0; i < this.size(); i++) {
			if (this.get(i).equals(s)) {
				return i;
			}
		}
		super.add(s);
		return i;
	}
    
	public String toString() {
		StringBuilder sb = new StringBuilder();
		Formatter f = new Formatter(sb);
		f.format("Strings table:\n");
		for (int i = 0; i < this.size(); i++) {
			f.format("Entry %d -- %s\n", i, this.get(i));
		}
		f.close();
		return sb.toString();
	}

}

package university;

public class Demo {

	public static void main(String[] args) {
		
		Studente enrico = new Studente("Enrico", "Bacis");
		
		// ERROR:
		// Studente enrico = new Studente("", "Bacis");
		// Studente enrico = new Studente("Enrico", "");
		
		
		// Inserisco 4 voti
		enrico.aggiungiVoto(30);
		enrico.aggiungiVoto(27);
		enrico.aggiungiVoto(18);
		enrico.aggiungiVoto(28);
		
		// ERROR:
		// enrico.aggiungiVoto(17);
		// enrico.aggiungiVoto(31);
		
		
		// Verifichiamo che la lista sia ordinata
		System.out.println("Voti Inseriti: " + enrico.getNumeroVoti());
		System.out.println(enrico);
		
		
		// Modifico l'anno di corso
		System.out.println();
		enrico.incrementaAnnocorso();
		System.out.println("Anno di corso: " + enrico.getAnnocorso());
		
		
		// Verifica di max, min, numerovoti
		System.out.println();
		System.out.println("Voto più basso: " + enrico.getMin());
		System.out.println("Secondo voto più basso: " + enrico.getVoto(1));
		System.out.println("Secondo voto più alto:  " + enrico.getVoto(enrico.getNumeroVoti() - 2));
		System.out.println("Voto più alto:  " + enrico.getMax());
		
		//ERROR:
		// System.out.println("Voto inesistente: " + enrico.getVoto(-1));
		// System.out.println("Voto inesistente: " + enrico.getVoto(enrico.getNumeroVoti()));
		
		
		// Cambio di identità
		enrico.setNome("Buffer");
		enrico.setCognome("Overflow");
		
		// ERROR:
		// enrico.setNome("");
		// enrico.setCognome("");
		System.out.println();
		System.out.println(enrico);
		
	}

}

package university;

public class Studente extends Persona {
	//@ private invariant (annocorso >= 1);
	
	private /*@ spec_public @*/ int annocorso;
	private /*@ spec_public non_null @*/ SortedList<Voto> voti;
	
	/*@ ensures (nome == getNome())
	  @		 && (cognome == getCognome())
	  @ 	 && (annocorso == 1)
	  @ 	 && (getNumeroVoti() == 0);
	  @*/
	Studente(/*@ non_null @*/ String nome, /*@ non_null @*/ String cognome) {
		super(nome, cognome);
		annocorso = 1;
		voti = new SortedList<Voto>();
	}

	//@ ensures \result == this.annocorso;
	public /*@ pure @*/ int getAnnocorso() {
		return annocorso;
	}
	
	//@ ensures this.annocorso == \old(annocorso) + 1;
	public void incrementaAnnocorso() {
			++annocorso;
	}
	
	//@ ensures getNumeroVoti() == \old(getNumeroVoti()) + 1;
	public void aggiungiVoto(int voto) {
		voti.add(new Voto(voto));
	}
	
	/*@ ensures \result >= 0
	  @		 && \result == voti.size();
	  @*/
	public /*@ pure @*/ int getNumeroVoti() {
		return voti.size();
	}
	
	//@ requires index >= 0;
	public Voto getVoto(int index) {
		return voti.get(index);
	}
	
	/*@ ensures (\forall int i; i >= 0 && i < getNumeroVoti() ==> (\result).compareTo(voti.get(i)) <= 0)
	  @ 	 && (\exists int i; i >= 0 && i < getNumeroVoti() ==> (\result).equals(voti.get(i)));
	  @*/
	public /*@ pure @*/ Voto getMin() {
		return voti.get(0); // La lista è ordinata in maniera non decrescente.
	}
	
	/*@ ensures (\forall int i; i >= 0 && i < getNumeroVoti() ==> (\result).compareTo(voti.get(i)) >= 0)
	  @ 	 && (\exists int i; i >= 0 && i < getNumeroVoti() ==> (\result).equals(voti.get(i)));
	  @*/
	public /*@ pure @*/ Voto getMax() {
		return voti.get(voti.size() - 1); // La lista è ordinata in maniera non decrescente.
	}
	
	/*@ also
	  @ ensures (\result).length() > 20;
	  @ */
	@Override
	public /*@ pure @*/ /*@ non_null @*/String toString() {
		return nome + " " + cognome + ", " + annocorso + "° anno, voti: " + voti.toString(); 
	}
	
}

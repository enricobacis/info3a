package university;

import java.security.InvalidParameterException;

public class Voto implements Comparable<Voto> {
	//@ private invariant (voto >= 18) && (voto <= 30);
	
	private /*@ spec_public non_null @*/ Integer voto;
	
	//@ ensures voto == getVoto();
	public Voto(int voto) {
		if (!(voto >= 18) && (voto <= 30))
			throw new InvalidParameterException("Voto non valido. Range di voti = [18, 30]");
		this.voto = voto;
	}
	
	//@ ensures \result == this.voto;
	public /*@ pure @*/ int getVoto() {
		return voto;
	}
	
	//@ ensures (voto == ((Voto)obj).voto) <== (\result == true);
	@Override
	public /*@ pure @*/ boolean equals(Object obj) {
		if (!(obj instanceof Voto)) return false;
		return voto.equals(((Voto)obj).voto);
	}
	
	/*@ ensures (voto <= other.voto) <==> (\result <= 0)
	  @ 	 && (voto >= other.voto) <==> (\result >= 0);
	  @*/
	@Override
	public /*@ pure @*/ int compareTo(/*@ non_null @*/ Voto other) {
		return voto.compareTo(other.getVoto()); 
	}
	
	@Override
	public /*@ pure @*/ /*@ non_null @*/ String toString() {
		return "" + voto.toString();
	}

}

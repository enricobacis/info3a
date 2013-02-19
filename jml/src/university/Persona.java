package university;

import java.security.InvalidParameterException;


public class Persona {
	/*@	private invariant nome != ""
	  @ 	    && cognome != "";
	  @*/
	
	protected /*@ spec_public non_null @*/ String nome;
	protected /*@ spec_public non_null @*/ String cognome;
	
	/*@ ensures (nome == getNome())
	  @		 && (cognome == getCognome());
	  @*/
	public Persona(/*@ non_null @*/ String nome, /*@ non_null @*/ String cognome) {
		setNome(nome);
		setCognome(cognome);
	}
	
	//@ ensures \result == this.nome;
	public /*@ pure @*/ String getNome() {
		return nome;
	}
	
	//@ ensures nome == getNome();
	public void setNome(/*@ non_null @*/ String nome) {
		if (nome == null || nome.isEmpty())
			throw new InvalidParameterException("Nome non valido");
		this.nome = nome;
	}
	
	//@ ensures \result == this.cognome;
	public /*@ pure @*/ String getCognome() {
		if (cognome == null || cognome.isEmpty())
			throw new InvalidParameterException("Cognome non valido");
		return cognome;
	}
	
	//@ ensures cognome == getCognome();
	public void setCognome(/*@ non_null @*/ String cognome) {
		this.cognome = cognome;
	}
	
	//@ ensures (\result).length() >= 3;
	@Override
	public /*@ pure @*/ /*@ non_null @*/ String toString() {
		return nome + " " + cognome;
	}
	
}

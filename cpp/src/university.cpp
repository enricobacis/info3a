#include "university.h"
#include "utilities.h"
#include <iostream>
#include <strings.h>

using namespace std;
using namespace std::tr1;

University *University::instance = NULL;

University::University():
		nome(""),
		ultima_matricola(0)
{
}

University::~University() {
	cout << endl << nome << " è stata distrutta" << endl;
	persone.clear();
}

University *University::getInstance() {
	return instance ? instance : (instance = new University());
}

string const& University::getNome() const {
	return nome;
}

void University::setNome (string const& nome) {
	this->nome = nome;
}

Studente* University::nuovoStudente (string const& nome, string const& cognome) {
	Studente* s = new Studente(nome, cognome);
	nuovaPersona(s);
	return s;
}

Professore* University::nuovoProfessore (string const& nome, string const& cognome) {
	Professore* p = new Professore(nome, cognome);
	nuovaPersona(p);
	return p;
}

Dottorando* University::nuovoDottorando (string const& nome, string const& cognome) {
	Dottorando* d = new Dottorando(nome, cognome);
	nuovaPersona(d);
	return d;
}

Persona* University::getPersona (long matricola) {
	unordered_map<long, Persona*>::const_iterator x = persone.find(matricola);
	if(x == persone.end())
	   return NULL;
	return x->second;
}

void University::find (std::string const& str) {
	cout << endl << "Ricerca di \"" << str << "\":" << endl;

	for (unordered_map<long, Persona*>::const_iterator i = persone.begin(); i != persone.end(); ++i) {
		std::string const& nome = i->second->getNome();
		std::string const& cognome = i->second->getCognome();
		if (strfindi(nome + " " + cognome, str))
			cout << i->first << "\t" << nome << " " << cognome << endl;
	}

	cout << "-----------------------" << endl;
}

long University::nuovaPersona (Persona* persona) {
	persone.insert(make_pair(++ultima_matricola, persona));
	cout << endl << "Matricola " << ultima_matricola << " creata" << endl;
	return ultima_matricola;
}

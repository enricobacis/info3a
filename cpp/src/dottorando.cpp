#include "dottorando.h"
#include <iostream>

using namespace std;

Dottorando::Dottorando(string const& nome, string const& cognome):
	Persona(nome, cognome)
{
}

Dottorando::~Dottorando() {
}


void Dottorando::printInfo() {
	cout << "Tipo: Dottorando" << endl;
	Persona::printInfo();
	Studente::printVoti();
	Professore::printCorsi();
}

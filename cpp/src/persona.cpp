#include "persona.h"
#include <iostream>

using namespace std;

Persona::Persona():
	nome(),
	cognome()
{
}

Persona::Persona(string const& nome, string const& cognome):
	nome(nome),
	cognome(cognome)
{
}

Persona::~Persona() {
}

string const& Persona::getCognome() const {
	return cognome;
}

void Persona::setCognome(string const& cognome) {
	this->cognome = cognome;
}

string const& Persona::getNome() const {
	return nome;
}

void Persona::setNome(string const& nome) {
	this->nome = nome;
}

void Persona::printInfo() {
	cout << "Nome: " << nome << endl
		 << "Cognome: " << cognome << endl;
}

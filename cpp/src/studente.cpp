#include <iostream>
#include "studente.h"
#include "voto.h"

using namespace std;

Studente::Studente()
{
	voti = new VotiContainer();
}

Studente::Studente(string const& nome, string const& cognome):
	Persona(nome, cognome)
{
	voti = new VotiContainer();
}

Studente::~Studente() {
	delete voti;
	voti = 0;
}

size_t Studente::registraVoto (string const& corso, unsigned short voto) {
	return voti->registraVoto(new Voto(corso, voto));
}

unsigned short Studente::getVoto (std::string const& corso) {
	return voti->getVoto(corso);
}

float Studente::getMediaVoti() {
	return voti->getMedia();
}

void Studente::printInfo() {
	cout << "Tipo: Studente" << endl;
	Persona::printInfo();
	printVoti();
}

void Studente::printVoti () {
	cout << "Voti:" << endl
		 << voti
		 << "-----------------------" << endl;
}

unsigned short Studente::operator[] (string const& corso) {
	return this->getVoto(corso);
}

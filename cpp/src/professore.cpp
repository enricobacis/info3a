#include "professore.h"
#include <iostream>
#include <algorithm>

using namespace std;

Professore::Professore():
	corsi()
{
}

Professore::Professore(string const& nome, string const& cognome):
	Persona(nome, cognome),
	corsi()
{
}

Professore::~Professore() {
}

void Professore::aggiungiCorso (std::string const& corso) {
	if (std::find(corsi.begin(), corsi.end(), corso) != corsi.end())
		cout << endl << "Corso \"" << corso << "\" già presente";
	else
		corsi.push_back(corso);
}

void Professore::rimuoviCorso (std::string const& corso) {
	vector<string>::iterator item = std::find(corsi.begin(), corsi.end(), corso);
	if (item == corsi.end())
		cout << endl << "Corso \"" << corso << "\" non presente";
	else
		corsi.erase(item);
}

void Professore::printInfo() {
	cout << "Tipo: Professore" << endl;
	Persona::printInfo();
	printCorsi();
}

void Professore::printCorsi () {
	cout << "Corsi:" << endl;
	for (vector<string>::const_iterator i = corsi.begin(); i != corsi.end(); ++i)
		cout << *i << endl;
	cout << "-----------------------" << endl;
}

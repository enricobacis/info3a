#include <iostream>
#include "university.h"
#include "voto.h"
#include "discounter.h"

using namespace std;

int main() {
	University *uni = University::getInstance();
	uni->setNome("Università di Bergamo");
	cout << uni->getNome() << endl;

	Discounter* v = new Discounter();

	Professore* p = uni->nuovoProfessore("Angelo", "Gargantini");
	p->aggiungiCorso("Informatica 3A");
	p->printInfo();
	p->accept(v);
	cout << endl << "Sconto: " << v->getValue() * 100.0f << "%" << endl;

	Studente* s = uni->nuovoStudente("Enrico", "Bacis");
	s->registraVoto("Informatica 3A", 30);
	s->printInfo();
	s->accept(v);
	cout << endl << "Sconto: " << v->getValue() * 100.0f << "%" << endl;

	Dottorando* d = uni->nuovoDottorando("Un", "Dottorando");
	d->registraVoto("Un Corso", 24);
	d->aggiungiCorso("Un Altro Corso");

	Persona* pd = (Persona*)d;
	pd->printInfo();
	pd->accept(v);
	cout << endl << "Sconto: " << v->getValue() * 100.0f << "%" << endl;

	uni->find("bacis");

	delete uni;
	return 0;
}

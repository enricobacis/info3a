#ifndef PROFESSORE_H_
#define PROFESSORE_H_

#include "persona.h"
#include <vector>

class Professore: public virtual Persona {
	friend class University;
	friend class Visitor; // Visitors are welcome!

public:
	virtual ~Professore ();

	void aggiungiCorso (std::string const& corso);
	void rimuoviCorso (std::string const& corso);

	virtual void printInfo ();
	void printCorsi ();

	virtual void accept (Visitor* visitor) { visitor->visit(this); }

protected:
	std::vector<std::string> corsi;

	Professore ();
	Professore (std::string const& nome, std::string const& cognome);

private:
	Professore (Professore const& other);
	void operator= (Professore const& other);

};

#endif /* PROFESSORE_H_ */

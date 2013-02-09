#ifndef STUDENTE_H_
#define STUDENTE_H_

#include "persona.h"
#include "voticontainer.h"
#include <string>

class Studente: public virtual Persona {
	friend class University;

public:
	virtual ~Studente ();

	size_t registraVoto (std::string const& corso, unsigned short voto);
	unsigned short getVoto (std::string const& corso);

	float getMediaVoti();
	virtual void printInfo ();
	void printVoti ();

	virtual void accept (Visitor* visitor) { visitor->visit(this); }
	unsigned short operator[] (std::string const& corso);

protected:
	VotiContainer *voti;

	Studente ();
	Studente (std::string const& nome, std::string const& cognome);

private:
	Studente (Studente const& other);
	void operator= (Studente const& other);
};

#endif /* STUDENTE_H_ */

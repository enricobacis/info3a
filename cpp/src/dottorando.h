#ifndef DOTTORANDO_H_
#define DOTTORANDO_H_

#include "studente.h"
#include "professore.h"

class Dottorando: public virtual Studente, public virtual Professore {
	friend class University;
	friend class Visitor; // Visitors are welcome!

public:
	virtual ~Dottorando();
	virtual void printInfo();
	virtual void accept (Visitor* visitor) { visitor->visit(this); }

protected:
	Dottorando(std::string const& nome, std::string const& cognome);

private:
	Dottorando (Dottorando const& other);
	void operator= (Dottorando const& other);
};

#endif /* DOTTORANDO_H_ */

#ifndef DISCOUNTER_H_
#define DISCOUNTER_H_

#include "visitor.h"

class Discounter: public ReturningVisitor<float> {

public:
	Discounter ();
	virtual ~Discounter ();

	virtual void visit (Studente*);
	virtual void visit (Professore*);
	virtual void visit (Dottorando*);

private:
	float calcolaSconto(float media);

};

#endif /* DISCOUNTER_H_ */

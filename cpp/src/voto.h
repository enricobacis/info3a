#ifndef VOTO_H_
#define VOTO_H_

#include <stdlib.h>
#include <string>

class Voto: private std::pair <std::string, unsigned short> {
	friend class VotiContainer;

public:
	Voto (std::string const& corso, unsigned short voto);
	virtual ~Voto ();

	std::string const& getCorso () const;
	unsigned short getVoto () const;

};

#endif /* VOTO_H_ */

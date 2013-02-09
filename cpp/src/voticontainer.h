#ifndef VOTICONTAINER_H_
#define VOTICONTAINER_H_

#include <string>
#include <map>
#include "voto.h"

class VotiContainer: private std::map <std::string, unsigned short> {
public:
	VotiContainer ();
	virtual ~VotiContainer ();

	// Ripubblicizzo i metodi che vondo rendere pubblici
	using std::map<std::string, unsigned short>::const_iterator;
	using std::map<std::string, unsigned short>::size;

	size_t registraVoto (Voto* voto);
	unsigned short getVoto (std::string const& corso) const;
	float getMedia ();
	void print ();

	unsigned short operator[] (std::string const& corso) const;

};

#endif /* VOTICONTAINER_H_ */

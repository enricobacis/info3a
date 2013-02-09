#include "voticontainer.h"
#include <iostream>
#include <numeric>

using namespace std;

VotiContainer::VotiContainer ()
{
}

VotiContainer::~VotiContainer () {
	this->clear();
}

size_t VotiContainer::registraVoto (Voto* voto) {
	if (voto->getVoto() < 18 || voto->getVoto() > 30)
		cout << endl << "È possibile registrare solo voti 18 <= x <= 30";
	else
		this->insert(*voto);

	return this->size();
}

float VotiContainer::getMedia () {
	if (this->empty())
		return 0.0f;

	int sum = 0;
	for (map<string, unsigned short>::const_iterator i = this->begin(); i != this->end(); ++i)
		sum += i->second;
	return ((float) sum) / size();
}

void VotiContainer::print () {
	for (map<string, unsigned short>::const_iterator i = this->begin(); i != this->end(); ++i)
		cout << i->second << "\t" << i->first << endl;
}

unsigned short VotiContainer::getVoto (string const& corso) const {
	map<string, unsigned short>::const_iterator x = this->find(corso);
	if(x == this->end())
	   return 0;
	return x->second;
}

unsigned short VotiContainer::operator[] (string const& corso) const {
	return getVoto(corso);
}

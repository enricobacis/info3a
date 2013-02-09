#include "voto.h"

using namespace std;

Voto::Voto(string const& corso, unsigned short voto):
	pair <string, unsigned short> (corso, voto)
{
}

Voto::~Voto() {
}

std::string const& Voto::getCorso() const {
	return first;
}

unsigned short Voto::getVoto() const {
	return second;
}

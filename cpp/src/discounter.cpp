#include "discounter.h"
#include "studente.h"
#include "professore.h"
#include "dottorando.h"

Discounter::Discounter() {
}

Discounter::~Discounter() {
}

void Discounter::visit (Studente* s) {
	setValue(calcolaSconto(s->getMediaVoti()));
}

void Discounter::visit (Professore* p) {
	setValue(1.0f); // 100%
}

void Discounter::visit (Dottorando* d) {
	setValue(0.5f + 0.5f * calcolaSconto(d->getMediaVoti()));
}

float Discounter::calcolaSconto(float media) {
	return (media == 0.0f) ? 0.0f : (media - 18.0f) / 12.0f;
}

#ifndef PERSONA_H_
#define PERSONA_H_

#include "visitable.h"
#include <string>

class Persona: public Visitable {

public:
	virtual ~Persona();

	std::string const& getCognome() const;
	void setCognome(std::string const& cognome);
	std::string const& getNome() const;
	void setNome(std::string const& nome);

	virtual void printInfo();

protected:
	Persona();
	Persona(std::string const& nome, std::string const& cognome);

private:
	std::string nome;
	std::string cognome;

	Persona (Persona const& other);
	void operator= (Persona const& other);
};

#endif /* PERSONA_H_ */

#ifndef UNIVERSITY_H_
#define UNIVERSITY_H_

#include <string>
#include <tr1/unordered_map>
#include "persona.h"
#include "studente.h"
#include "professore.h"
#include "dottorando.h"

class University {

public:
	static University *getInstance ();
	~University ();

	std::string const& getNome () const;
	void setNome (std::string const& nome);

	Studente* nuovoStudente (std::string const& nome, std::string const& cognome);
	Professore* nuovoProfessore (std::string const& nome, std::string const& cognome);
	Dottorando* nuovoDottorando (std::string const& nome, std::string const& cognome);

	Persona* getPersona (long matricola);
	Persona* operator[] (long matricola);
	void find (std::string const& str);

private:
	static University *instance;

	std::string nome;
	long ultima_matricola;
	std::tr1::unordered_map<long, Persona*> persone;

	University ();
	University (University const& other);
	void operator= (University const& other);

	long nuovaPersona (Persona* persona);

};

#endif /* UNIVERSITY_H_ */

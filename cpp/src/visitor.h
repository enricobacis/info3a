#ifndef VISITOR_H_
#define VISITOR_H_

class Studente;
class Professore;
class Dottorando;

template <typename ReturnType>
class ReturningVisitor;

class Visitor
{
public:
	virtual ~Visitor() { }
	virtual void visit (Studente*) = 0;
	virtual void visit (Professore*) = 0;
	virtual void visit (Dottorando*) = 0;
};

template <typename ReturnType>
class ReturningVisitor: public Visitor
{
public:
	ReturnType const& getValue () { return value; }

protected:
	void setValue (ReturnType const& value) { this->value = value; }

private:
	ReturnType value;
};

#endif /* VISITOR_H_ */

#include "../include/Ice.h"

/***  Costructor ***/
Ice::Ice() : AMateria("ice") {}

/***  Copy costructor ***/
Ice::Ice( const Ice& other ) : AMateria(other) {}

/***  Assignement operator override ***/
Ice& Ice::operator=( const Ice& other )
{
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

/***  Destructor ***/
Ice::~Ice() {}

AMateria*	Ice::clone( void ) const
{
	return new Ice(*this);
}

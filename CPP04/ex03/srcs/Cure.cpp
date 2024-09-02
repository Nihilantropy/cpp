#include "../include/Cure.h"

/***  Costructor ***/
Cure::Cure() : AMateria("cure") {}

/***  Copy costructor ***/
Cure::Cure( const Cure& other ) : AMateria(other) {}

/***  Assignement operator override ***/
Cure& Cure::operator=( const Cure& other )
{
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

/***  Destructor ***/
Cure::~Cure() {}

AMateria*	Cure::clone( void ) const
{
	return new Cure(*this);
}

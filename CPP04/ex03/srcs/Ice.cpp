#include "../include/Ice.h"

/***  Costructor ***/
Ice::Ice() : AMateria("ice") {}

/***  Copy costructor ***/
Ice::Ice( const Ice& other ) : AMateria(other) {}

/***  assignment operator override ***/
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
	std::cout << "Clone method called for " << _type << " Materia" << std::endl;
	return new Ice(*this);
}

void	Ice::use( ICharacter& target )
{
	std::cout << "* shoot an ice bolt at " << target.getName() << " *" << std::endl;
}
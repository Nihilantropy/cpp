#include "Ice.h"

/*** constructor ***/
Ice::Ice() : AMateria("ice") {}

/*** copy constructor ***/
Ice::Ice( const Ice& other ) : AMateria(other) {}

/*** assignment operator ***/
Ice& Ice::operator=( const Ice& other )
{
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

/*** destructor ***/
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
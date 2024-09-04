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
	std::cout << "Clone method called for " << _type << " Materia" << std::endl;
	return new Cure(*this);
}

void	Cure::use( ICharacter& target )
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
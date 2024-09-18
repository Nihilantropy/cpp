#include "../include/AMateria.h"

/***  Costructor ***/
AMateria::AMateria( const std::string& type ) : _type(type) { std::cout << "Costructor called for " << _type << " AMateria" << std::endl; }

/***  Copy costructor ***/
AMateria::AMateria( const AMateria& other ) : _type(other._type) { (void)other; std::cout << "Copy costructor called for " << _type << " AMateria" << std::endl; }

/***  assignment operator override ***/
AMateria& AMateria::operator=( const AMateria& other )
{
	if (this != &other)
		std::cout << "assignment operator called for " << _type << " AMateria" << std::endl;
	return *this;
}

/***  Destructor ***/
AMateria::~AMateria() { std::cout << "Destructor called for " << _type << " AMateria" << std::endl; }

/*** Getters ***/
const std::string& AMateria::getType( void ) const { return _type; }

/*** Public Methods ***/
void AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << "Using " << _type << " on character." << std::endl;
}

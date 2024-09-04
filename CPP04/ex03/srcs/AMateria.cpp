#include "../include/AMateria.h"

/***  Costructor ***/
AMateria::AMateria( const std::string& type ) : _type(type) { std::cout << "Costructor called for " << _type << " AMateria" << std::endl; }

/***  Copy costructor ***/
AMateria::AMateria( const AMateria& other ) : _type(other._type) { std::cout << "Copy costructor called for " << _type << " AMateria" << std::endl; }

/***  Assignement operator override ***/
AMateria& AMateria::operator=( const AMateria& other )
{
	std::cout << "Assignement operator called for " << _type << " AMateria" << std::endl;
	if (this != &other)
		this->_type = other._type;
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

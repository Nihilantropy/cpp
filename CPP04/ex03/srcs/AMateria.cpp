#include "../include/AMateria.h"

/***  Costructor ***/
AMateria::AMateria( const std::string& type ) : _type(type) {}

/***  Copy costructor ***/
AMateria::AMateria( const AMateria& other ) : _type(other._type) {}

/***  Assignement operator override ***/
AMateria& AMateria::operator=( const AMateria& other )
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

/***  Destructor ***/
AMateria::~AMateria() {}

/*** Getters ***/
const std::string& AMateria::getType( void ) const { return _type; }

/*** Public Methods ***/
void AMateria::use(ICharacter& target)
{
	std::cout << "Using " << _type << " on character." << std::endl;
}

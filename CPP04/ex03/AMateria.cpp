#include "AMateria.h"

/*** constructor ***/
AMateria::AMateria( const std::string& type ) : _type(type) { std::cout << "constructor called for " << _type << " AMateria" << std::endl; }

/*** copy constructor ***/
AMateria::AMateria( const AMateria& other ) : _type(other._type) { (void)other; std::cout << "Copy constructor called for " << _type << " AMateria" << std::endl; }

/*** assignment operator ***/
AMateria& AMateria::operator=( const AMateria& other )
{
	if (this != &other)
		std::cout << "assignment operator called for " << _type << " AMateria" << std::endl;
	return *this;
}

/*** destructor ***/
AMateria::~AMateria() { std::cout << "Destructor called for " << _type << " AMateria" << std::endl; }

/*** getters ***/
const std::string& AMateria::getType( void ) const { return _type; }

/*** public Methods ***/
void AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << "Using " << _type << " on character." << std::endl;
}

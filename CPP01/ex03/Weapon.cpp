#include "Weapon.h"

/*** constructor ***/
Weapon::Weapon( const std::string& type ) : _type(type) {}

/*** copy constructor ***/
Weapon::Weapon( const Weapon& other )
{
	this->_type = other._type;
}

/*** assignment operator ***/
Weapon& Weapon::operator=( const Weapon& other )
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

/*** destructor ***/
Weapon::~Weapon() {}

/*** getter ***/
const std::string&	Weapon::getType( void ) const
{
	return _type;
}

/*** setter ***/
void	Weapon::setType( const std::string& newType )
{
	_type = newType;
}

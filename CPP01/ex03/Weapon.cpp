#include "Weapon.h"

Weapon::Weapon( const std::string& type ) : _type(type) {}

Weapon::~Weapon() {}

/*** getter ***/
const std::string&	Weapon::getType() const
{
	return _type;
}

/*** setter ***/
void	Weapon::setType( const std::string& newType )
{
	_type = newType;
}

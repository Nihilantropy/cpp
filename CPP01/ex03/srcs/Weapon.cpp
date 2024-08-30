#include "..//include/Weapon.h"
#include "Weapon.h"

Weapon::Weapon( const std::string& type ) : _type(type) {}

Weapon::~Weapon()
{
	// Destructor implementation
}

const std::string&	Weapon::getType() const
{
	return _type;
}

void	Weapon::setType( const std::string& newType )
{
	_type = newType;
}

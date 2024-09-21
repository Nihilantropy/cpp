#include "HumanA.h"

/*** constructor ***/
HumanA::HumanA( const std::string& name, Weapon& weapon ) : _name(name), _weapon(weapon) {}

/*** copy constructor ***/
HumanA::HumanA( const HumanA& other )
{
	this->_name = other._name;
	this->_weapon = other._weapon;
}

/*** assignment operator ***/
HumanA& HumanA::operator=( const HumanA& other )
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_weapon = other._weapon;
	}
	return *this;
}

/*** destructor ***/
HumanA::~HumanA() {}

/*** public methods ***/
void	HumanA::attack() const
{
	std::cout << _name << " attack with their " << _weapon.getType() << std::endl;
}
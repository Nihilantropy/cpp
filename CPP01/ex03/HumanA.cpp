#include "HumanA.h"

/*** costructor ***/
HumanA::HumanA( const std::string& name, Weapon& weapon ) : _name(name), _weapon(weapon) {}

/*** copy costructor ***/
HumanA::HumanA( const HumanA& other ) : _name(other._name), _weapon(other._weapon) {}

/*** assignment operator ***/
HumanA& HumanA::operator=( const HumanA& other )
{
	if (this != &other)
	{
		this->_name = other._name;
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
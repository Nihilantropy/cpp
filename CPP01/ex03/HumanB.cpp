#include "HumanB.h"

HumanB::HumanB( const std::string& name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB() {}

/*** public methods ***/
void	HumanB::setWeapon( Weapon& weapon )
{
	_weapon = &weapon;
}

void	HumanB::attack() const
{
 	if (_weapon)
		std::cout << _name << " attack with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " has no weapon to attack the enemy!" << std::endl;
}

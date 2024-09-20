#include "HumanA.h"

HumanA::HumanA( const std::string& name, Weapon& weapon ) : _name(name), _weapon(weapon) {}

HumanA::~HumanA() {}

/*** public methods ***/
void	HumanA::attack() const
{
	std::cout << _name << " attack with their " << _weapon.getType() << std::endl;
}
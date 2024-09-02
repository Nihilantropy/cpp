#include <DiamondTrap.h>

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name + "_clap_name"), _name(name)
{
	_hitPoints = FragTrap::getEnergyPoints();
	_energyPoints = ScavTrap::getEnergyPoints();
	_attackDamage = FragTrap::getAttackDamage();
}

DiamondTrap::~DiamondTrap() { std::cout << "DiamondTrap Destructor called!" << std::endl; }

void	DiamondTrap::attack( const std::string& target ) { ScavTrap::attack(target); }

void	DiamondTrap::whoAmI( void )
{
	std::cout << "I am " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}


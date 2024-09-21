#include "DiamondTrap.h"

/*** costrucotr ***/
DiamondTrap::DiamondTrap( const std::string& name )
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	_hitPoints = FragTrap::getEnergyPoints();
	_energyPoints = ScavTrap::getEnergyPoints();
	_attackDamage = FragTrap::getAttackDamage();
}

/*** copy constructor ***/
DiamondTrap::DiamondTrap( const DiamondTrap& other ) : ClapTrap(other), ScavTrap(other), FragTrap(other) {}

/*** assignment operator ***/
DiamondTrap& DiamondTrap::operator=( const DiamondTrap& other )
{
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

/*** destructor ***/
DiamondTrap::~DiamondTrap() { std::cout << "DiamondTrap Destructor called!" << std::endl; }

/*** public methods ***/
void	DiamondTrap::attack( const std::string& target ) { ScavTrap::attack(target); }

void	DiamondTrap::whoAmI( void )
{
	std::cout << "I am " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}

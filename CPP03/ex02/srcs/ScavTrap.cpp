#include "../include/ScavTrap.h"

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap constructor called for " << _name << std::endl;
}

ScavTrap::~ScavTrap() { std::cout << "ScavTrap Destructor called!" << std::endl; }

void	ScavTrap::attack( const std::string& target )
{
	if (_energyPoints <= 0)
	{
		std::cout << _name << " has 0 energy points. The attack has failed :(" << std::endl;
		return ;
	}

	std::cout << _name << " ferociously attacks " << target << ", dealing " << _attackDamage << " points of damage!" << std::endl;

	_energyPoints -= 1;
	if (_energyPoints <= 0)
		std::cout << _name << " has finished all his energy points. cannot attack or rapair anymore." << std::endl;
	else
		std::cout << _name << " new energy points count is: " << _energyPoints << std::endl;
	setEnergyPoints( _energyPoints );
}


void	ScavTrap::guardGate( void )
{
	std::cout << _name << " is now in Gate keeper mode." << std::endl;
}

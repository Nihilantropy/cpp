#include "FragTrap.h"

/*** default constructor ***/
FragTrap::FragTrap() : ClapTrap("Deafult FragTrap") {}

/*** constructor ***/
FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap constructor called for " << _name << std::endl;
}

/*** copy constructor ***/
FragTrap::FragTrap( const FragTrap& other ) : ClapTrap(other) {}

/*** assignment operator ***/
FragTrap& FragTrap::operator=( const FragTrap& other )
{
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

/*** destructor ***/
FragTrap::~FragTrap() { std::cout << "FragTrap Destructor called!" << std::endl; }

/*** public methods ***/
void	FragTrap::highFivesGuys( void )
{
	std::cout << _name << " requests a high five! \"Hey you there! Give me your best high five of your life!\"" << std::endl;
}

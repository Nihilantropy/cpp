#include "../include/ClapTrap.h"

ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Costructor called!" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& other )
{
	*this = other;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& other )
{
	(void)other;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called!" << std::endl;
}

/*** getter and setter methods ***/
std::string	ClapTrap::getName( void ) const { return _name; }
int			ClapTrap::getHitPoints( void ) const { return _hitPoints; }
void		ClapTrap::setHitPoints( int hitPoints ) { _hitPoints = hitPoints; }
int			ClapTrap::getEnergyPoints( void ) const { return _energyPoints; }
void		ClapTrap::setEnergyPoints( int energyPoints ) { _energyPoints = energyPoints; }
int			ClapTrap::getAttackDamage( void ) const { return _attackDamage; }
void		ClapTrap::setAttackDamage( int attackDamage ) { _attackDamage = attackDamage; }

/*** public methods ***/

void	ClapTrap::attack( const std::string& target )
{
	int			currentEnergyPoints;
	std::string	name;

	currentEnergyPoints = getEnergyPoints();
	name = getName();

	if (currentEnergyPoints <= 0)
	{
		std::cout << name << " has 0 energy points. The attack has failed :(" << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	
	int	newEnergyPoints = currentEnergyPoints - 1;

	if (newEnergyPoints == 0)
		std::cout << "ClapTrap " << name << " has finished all his energy points. cannot attack or rapair anymore." << std::endl;
	else
		std::cout << "ClapTrap " << name << " new energy points count is: " << newEnergyPoints << std::endl;
	setEnergyPoints( newEnergyPoints );
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	int			currentHitPoints;
	std::string	name;

	currentHitPoints = getHitPoints();
	name = getName();
	
	if (currentHitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " is already dead..." << std::endl;
		return ;
	}

	int newHitPoints = currentHitPoints - amount;

	if (newHitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " took far too much damage, and now is dead. What a terrible loss..." << std::endl;
		newHitPoints = 0;
	}
	else
	{
		std::cout << "ClapTrap " << name << " took " << amount << " points of damage! Ouch...\n"
					"New hit points count is: " << newHitPoints << std::endl;
	}
	setHitPoints( newHitPoints );
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	int			currentHitPoints;
	int			currentEnergyPoints;
	std::string	name;

	currentHitPoints = getHitPoints();
	currentEnergyPoints = getEnergyPoints();
	name = getName();

	if ( currentEnergyPoints <= 0 )
	{
		std::cout << "ClapTrap " << name << " has 0 energy points. The repair has failed :(" << std::endl;
		return ;
	}

	int	newHitPoints = currentHitPoints + amount;
	int	newEnergyPoints = currentEnergyPoints - 1;

	if (newHitPoints > 10 )
	{
		std::cout << "Sorry partner, ClapTrap " << name << " are capped to 10." << std::endl;
		newHitPoints = 10;
	}
	else
	{
		std::cout << "ClapTrap " << name << " repaired for " << amount << " hit points!\n"
					"New hit points count is: " << newHitPoints << std::endl;
	}
	if (newEnergyPoints == 0)
		std::cout << "ClapTrap " << name << " has finished all his energy points. cannot attack or rapair anymore." << std::endl;
	else
		std::cout << "ClapTrap " << name << " new energy points count is: " << newEnergyPoints << std::endl;
	setHitPoints( newHitPoints );
	setEnergyPoints ( newEnergyPoints );

}


#include "ClapTrap.h"

/*** costructor ***/
ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap costructor called" << std::endl;
}

/*** copy costructor ***/
ClapTrap::ClapTrap( const ClapTrap& other )
{
	*this = other;
	std::cout << "ClapTrap copy costructor called for " << _name << std::endl;
}

/*** assignment operator ***/
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap assignment operator called for " << _name << std::endl;
	return *this;
}

/*** destructor ***/
ClapTrap::~ClapTrap() { std::cout << "ClapTrap Destructor called!" << std::endl; }

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
	if (_energyPoints <= 0)
	{
		std::cout << _name << " has 0 energy points. The attack has failed :(" << std::endl;
		return ;
	}

	std::cout << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	
	_energyPoints -= 1;

	if (_energyPoints == 0)
		std::cout << _name << " has finished all his energy points. cannot attack or rapair anymore." << std::endl;
	else
		std::cout << _name << " new energy points count is: " << _energyPoints << std::endl;
	setEnergyPoints( _energyPoints );
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (_hitPoints <= 0)
	{
		std::cout << _name << " is already dead..." << std::endl;
		return ;
	}

	_hitPoints -= amount;

	if (_hitPoints <= 0)
	{
		std::cout << _name << " took far too much damage, and now is dead. What a terrible loss..." << std::endl;
		_hitPoints = 0;
	}
	else
	{
		std::cout << _name << " took " << amount << " points of damage! Ouch...\n"
					"New hit points count is: " << _hitPoints << std::endl;
	}
	setHitPoints( _hitPoints );
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (_energyPoints <= 0)
	{
		std::cout << _name << " has 0 energy points. The repair has failed :(" << std::endl;
		return ;
	}

	_hitPoints += amount;
	_energyPoints -= 1;

	std::cout << _name << " repaired for " << amount << " hit points!\n"
					"New hit points count is: " << _hitPoints << std::endl;
	if (_energyPoints == 0)
		std::cout  << _name << " has finished all his energy points. cannot attack or rapair anymore." << std::endl;
	else
		std::cout << _name << " new energy points count is: " << _energyPoints << std::endl;
	setHitPoints( _hitPoints );
	setEnergyPoints ( _energyPoints );

}


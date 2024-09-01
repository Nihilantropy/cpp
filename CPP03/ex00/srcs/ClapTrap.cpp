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
int		ClapTrap::getHitPoints( void ) const { return _hitPoints }
void	ClapTrap::setHitPoints( int hitPoints ) { _hitPoints = hitPoints }
int		ClapTrap::getEnergyPoints( void ) const { return _energyPoints }
void	ClapTrap::setEnergyPoints( int energyPoints ) { _energyPoints = energyPoints }
int		ClapTrap::getAttackDamage( void ) const { return _attackDamage }
void	ClapTrap::setAttackDamage( int attackDamage ) { _attackDamage = attackDamage }

void	ClapTrap::attack( const std::string& target )
{
	std::cout << target << " lost " << _attackDamage << std::endl;
}


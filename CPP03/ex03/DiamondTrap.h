#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

# include "ScavTrap.h"
# include "FragTrap.h"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	/*** costructor ***/
	DiamondTrap( std::string name );
	/*** destructor ***/
	~DiamondTrap();

	/*** public methods ***/
	void	attack( const std::string& target );
	void	whoAmI( void );

private:
	std::string	_name;
};

#endif

#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

# include "ScavTrap.h"
# include "FragTrap.h"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	/*** constructor ***/
	DiamondTrap( const std::string& name );
	/*** copy constructor ***/
	DiamondTrap( const DiamondTrap& other );
	/*** assignment operator ***/
	DiamondTrap& operator=( const DiamondTrap& other );
	/*** destructor ***/
	~DiamondTrap();

	/*** public methods ***/
	void	attack( const std::string& target );
	void	whoAmI( void );

private:
	std::string	_name;
};

#endif

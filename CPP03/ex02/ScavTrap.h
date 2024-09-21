#ifndef SCAVTRAP_H
#define SCAVTRAP_H

# include <iostream>
# include <string>
# include "ClapTrap.h"

class ScavTrap : public ClapTrap
{
public:
	/*** constructor ***/
	ScavTrap( std::string name );
	/*** copy constructor ***/
	ScavTrap( const ScavTrap& other );
	/*** assignment operator ***/
	ScavTrap& operator=( const ScavTrap& other );
	/*** destructor ***/
	~ScavTrap();

	/*** public methods ***/
	void	attack( const std::string& target );
	void	guardGate( void );
};

#endif

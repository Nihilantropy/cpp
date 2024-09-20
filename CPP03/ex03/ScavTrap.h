#ifndef SCAVTRAP_H
#define SCAVTRAP_H

# include "ClapTrap.h"

class ScavTrap : virtual public ClapTrap
{
public:
	/*** costructor ***/
	ScavTrap( std::string name = "Default ScavTrap" );
	/*** destructor ***/
	~ScavTrap();

	/*** public methods ***/
	void	attack( const std::string& target );
	void	guardGate( void );
};

#endif

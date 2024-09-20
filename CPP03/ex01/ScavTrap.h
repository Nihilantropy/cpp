#ifndef SCAVTRAP_H
#define SCAVTRAP_H

# include "ClapTrap.h"

class ScavTrap : public ClapTrap
{
public:
	/*** costructor ***/
	ScavTrap(std::string name );
	/*** destructor ***/
	~ScavTrap();

	/*** public methods ***/
	void	attack( const std::string& target );
	void	guardGate( void );
};

#endif

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

# include "ClapTrap.h"

class FragTrap : virtual public ClapTrap
{
public:
	/*** costructor ***/
	FragTrap( std::string name = "Default FragTrap" );
	/*** destructor ***/
	~FragTrap();

	/*** public methods ***/
	void	highFivesGuys( void );
};

#endif

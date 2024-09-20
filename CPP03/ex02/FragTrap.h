#ifndef FRAGTRAP_H
#define FRAGTRAP_H

# include "ClapTrap.h"

class FragTrap : public ClapTrap
{
public:
	/*** costructor ***/
	FragTrap( std::string name );
	/*** destructor ***/
	~FragTrap();

	/*** public methods ***/
	void	highFivesGuys( void );
};

#endif

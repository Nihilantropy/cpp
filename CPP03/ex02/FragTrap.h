#ifndef FRAGTRAP_H
#define FRAGTRAP_H

# include "ClapTrap.h"

class FragTrap : public ClapTrap
{
public:
	/*** constructor ***/
	FragTrap( std::string name );
	/*** copy constructor ***/
	FragTrap( const FragTrap& other );
	/*** assignment operator ***/
	FragTrap& operator=( const FragTrap& other );
	/*** destructor ***/
	~FragTrap();

	/*** public methods ***/
	void	highFivesGuys( void );
};

#endif

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

# include "ClapTrap.h"

class FragTrap : virtual public ClapTrap
{
public:
	/*** default costructor ***/
	FragTrap();
	/*** costructor ***/
	FragTrap( std::string name );
	/*** copy costructor ***/
	FragTrap( const FragTrap& other );
	/*** assignment operator ***/
	FragTrap& operator=( const FragTrap& other );
	/*** destructor ***/
	virtual ~FragTrap();

	/*** public methods ***/
	void	highFivesGuys( void );
};

#endif

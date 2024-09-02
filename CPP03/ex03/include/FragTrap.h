#ifndef FRAGTRAP_H
#define FRAGTRAP_H

# include <ClapTrap.h>

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap( std::string name = "Default FragTrap");
	~FragTrap();

	void	highFivesGuys( void );
};

#endif

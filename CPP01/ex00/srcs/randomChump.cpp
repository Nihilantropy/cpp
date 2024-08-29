# include <iostream>
# include "../include/Zombie.h"

void	randomChump( std::string name )
{
	Zombie	zombie(name);

	zombie.announce();
}
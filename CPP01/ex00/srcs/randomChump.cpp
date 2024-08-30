# include "../include/Zombie.h"

/*	randomChump:
		Instantiate a new Zombie class on the stack and call
		the announce method.
		The destructor get call when the function terminate.
*/
void	randomChump( std::string name )
{
	Zombie	zombie;
	zombie.setName(name);
	zombie.announce();
}
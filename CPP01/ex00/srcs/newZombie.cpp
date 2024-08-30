# include "../include/Zombie.h"

/*	newZombie:
		Allocate space on the heap for a new Zombie class
		using the keyword 'new'.
		Return a pointer to the new allocated class.
*/
Zombie*	newZombie( std::string name )
{
	return (new Zombie(name));
}
# include <iostream>
# include "../include/Zombie.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	Zombie	*zombie;

	zombie = newZombie(argv[1]);
	zombie->announce();
	randomChump(argv[2]);
	delete zombie;
	return (0);
}
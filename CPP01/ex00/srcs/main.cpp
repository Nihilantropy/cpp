# include "../include/Zombie.h"

int	main(int argc, char **argv)
{
	std::string	zombieName1;
	std::string	zombieName2;

	if (argc == 1)
	{
		zombieName1 = "Eren";
		zombieName2 = "Sasha";
	}
	else if (argc > 1)
	{
		zombieName1 = argv[1];
		zombieName2 = argv[2];
	}
	Zombie	*zombie;

	zombie = newZombie(zombieName1);
	zombie->announce();
	delete zombie;
	randomChump(zombieName2);
	return (0);
}
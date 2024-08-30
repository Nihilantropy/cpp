# include "../include/Zombie.h"

int	main(int argc, char **argv)
{
	Zombie		*horde;
	int			N;
	std::string	name;

	if (argc == 1)
	{
		std::cerr << "Provide the horde number and name." << std::endl;
		return 1;
	}
	N = std::atoi(argv[1]);
	name = argv[2];
	horde = zombieHorde(N, name);
	if (!horde)
	{
		std::cerr << "Failed to create zombie horde." << std::endl;
		return 1;
	}
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
	return 0;
}
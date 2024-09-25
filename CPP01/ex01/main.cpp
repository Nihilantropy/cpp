#include "Zombie.h"
#include <typeinfo>

int	main(int argc, char **argv)
{
	Zombie		*horde;
	int			N;
	std::string	name;

	if (argc != 3)
	{
		std::cerr << "Usage\n"
					<< "./moarbrainz horde_number(ex. 10) horde_name(ex. \"Giampiero\")"
					<< std::endl;
		return 1;
	}
	N = atoi(argv[1]);
	if (N < 1 || N > 9999)
	{
		std::cerr << "Horde number must range from 1 to 9999 for humanity's sake" << std::endl;
		return 1;
	}
	name = argv[2];
	if (name.length() > 20)
	{
		std::cerr << "Parent sure hated horde... give it a shorter name" << std::endl;
		return 1;
	}
	if (name.empty())
	{
		std::cerr << "Use a real name!" << std::endl;
		return 1;
	}
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
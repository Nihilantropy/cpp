# include "Zombie.h"
# include <climits>

# define NAME_LIMIT 25000

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie* horde;

	if (N <= 0 || N > INT_MAX)
	{
		std::cerr << "Invalid number of zombies." << std::endl;
		return NULL;
	}
	if (name.length() > NAME_LIMIT)
	{
		std::cerr << "Horde name is too long." << std::endl;
		return NULL;
	}
	horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return horde;
}
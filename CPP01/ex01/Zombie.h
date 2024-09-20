#ifndef ZOMBIE_H
#define ZOMBIE_H

# include <string>
# include <iostream>
# include <cstdlib>

class Zombie
{
public:
	Zombie();
	~Zombie();

	void	setName( std::string name );
	void	announce( void );

private:
	std::string	_name;
};

Zombie*	zombieHorde( int N, std::string name );

#endif

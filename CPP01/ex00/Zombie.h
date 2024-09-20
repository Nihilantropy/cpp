#ifndef ZOMBIE_H
#define ZOMBIE_H

# include <string>
# include <iostream>

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

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif

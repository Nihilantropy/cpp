#ifndef ZOMBIE_H
#define ZOMBIE_H

# include <string>
# include <iostream>

class Zombie
{
public:
	/*** constructor ***/
	Zombie();
	/*** copy constructor ***/
	Zombie( const Zombie& other );
	/*** assignment operator ***/
	Zombie& operator=( const Zombie& other );
	/*** Destructor ***/
	~Zombie();
	
	/*** getter ***/
	const std::string	getName( void ) const;
	/*** setter ***/
	void				setName( std::string& name );
	void				announce( void );

private:
	std::string	_name;
};

void	randomChump( std::string name );
Zombie*	newZombie( std::string name );

#endif

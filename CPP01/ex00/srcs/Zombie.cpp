# include "..//include/Zombie.h"
# include <iostream>

// Constructor
Zombie::Zombie( std::string name ) : _name(name) {}

// Member function
void	Zombie::announce( void )
{
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

// Destructor
Zombie::~Zombie()
{
	std::cout << "Zombie " << this->_name << " is dead" << std::endl;
}
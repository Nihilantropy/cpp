# include "../include/Zombie.h"

// Constructor
Zombie::Zombie() : _name("") {}

// Destructor
Zombie::~Zombie()
{
	std::cout << "Zombie " << this->_name << " is dead" << std::endl;
}

// public set name method
void	Zombie::setName( std::string name )
{
	_name = name;
}

// Member function
void	Zombie::announce( void )
{
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

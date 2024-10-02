# include "Zombie.h"

/*** costructor ***/
Zombie::Zombie() : _name("") {}

/*** copy costructor ***/
Zombie::Zombie( const Zombie& other )
{
	this->_name = other._name;
}

/*** assignment operator ***/
Zombie&	Zombie::operator=( const Zombie& other )
{
	if (this != &other)
		this->_name = other._name;
	return *this;
}

/*** Destructor ***/
Zombie::~Zombie()
{
	std::cout << "Zombie " << this->_name << " is dead" << std::endl;
}

/*** getter ***/
const std::string	Zombie::getName( void ) const { return _name; }

/*** setters ***/
void	Zombie::setName( std::string& name )
{
	_name = name;
}

/*** public methods ***/
void	Zombie::announce( void )
{
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

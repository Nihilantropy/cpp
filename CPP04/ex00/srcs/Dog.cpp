#include <Dog.h>

Dog::Dog()
{
	_type = "Dog";
	std::cout << "Dog costructor called" << std::endl;
}

Dog::~Dog() { std::cout << "Dog destructor called" << std::endl;}

void	Dog::makeSound( void ) const
{
	std::cout << "Bau Bau" << std::endl;
}


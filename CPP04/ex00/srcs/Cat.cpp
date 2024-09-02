#include "Cat.h"

Cat::Cat()
{
	_type = "Cat";
	std::cout << "Cat costructor called" << std::endl;
}

Cat::~Cat() { std::cout << "Cat destructor called" << std::endl;}

void	Cat::makeSound( void ) const
{
	std::cout << "Miaoooooooo" << std::endl;
}


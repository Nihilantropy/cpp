#include "Cat.h"

/*** constructor ***/
Cat::Cat()
{
	_type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

/*** copy constructor ***/
Cat::Cat( const Cat& other ) : Animal(other) {}

/*** assignment operator ***/
Cat&	Cat::operator=( const Cat& other )
{
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

/*** destructor ***/
Cat::~Cat() { std::cout << "Cat destructor called" << std::endl;}

/*** public methods override ***/
void	Cat::makeSound( void ) const
{
	std::cout << "Miaoooooooo" << std::endl;
}

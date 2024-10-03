#include "Dog.h"

/*** constructor ***/
Dog::Dog()
{
	_type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

/*** copy constructor ***/
Dog::Dog( const Dog& other ) : Animal(other) {}

/*** assignment operator ***/
Dog&	Dog::operator=( const Dog& other )
{
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

/*** destructor ***/
Dog::~Dog() { std::cout << "Dog destructor called" << std::endl;}

/*** public methods override ***/
void	Dog::makeSound( void ) const
{
	std::cout << "Bau Bau" << std::endl;
}


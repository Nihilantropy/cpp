#include "Animal.h"

Animal::Animal() : _type("") { std::cout << "Animal costructor called" << std::endl; }

Animal::Animal( const Animal& other ) { *this = other; }

Animal& Animal::operator=( const Animal& other )
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

/*** Getters ***/
std::string	Animal::getType( void ) const { return _type; }

/*** public methods ***/
void	Animal::makeSound( void ) const
{
	std::cout << "..." << std::endl;
}

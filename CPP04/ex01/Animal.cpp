#include "Animal.h"

/*** constructor ***/
Animal::Animal() : _type("") { std::cout << "Animal constructor called" << std::endl; }

/*** copy constructor ***/
Animal::Animal( const Animal& other ) { *this = other; }

/*** assignment operator ***/
Animal& Animal::operator=( const Animal& other )
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}

/*** destructor ***/
Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

/*** getters ***/
std::string	Animal::getType( void ) const { return _type; }

/*** public methods virtual ***/
void	Animal::makeSound( void ) const
{
	std::cout << "..." << std::endl;
}

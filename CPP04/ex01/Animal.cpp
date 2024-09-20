#include "Animal.h"

/*** costructor ***/
Animal::Animal() : _type("") { std::cout << "Animal costructor called" << std::endl; }

/*** copy costructor ***/
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

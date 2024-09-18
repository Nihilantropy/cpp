#include "Animal.h"

/***  Costructor ***/
Animal::Animal() : _type("") { std::cout << "Animal costructor called" << std::endl; }

/***  Copy costructor ***/
Animal::Animal( const Animal& other ) { *this = other; }

/*** assignment operator override ***/
Animal& Animal::operator=( const Animal& other )
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}

/***  Destructor ***/
Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

/*** Getters ***/
std::string	Animal::getType( void ) const { return _type; }

/*** public methods ***/
void	Animal::makeSound( void ) const
{
	std::cout << "..." << std::endl;
}


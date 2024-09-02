#include "../include/AAnimal.h"

/***  Costructor ***/
AAnimal::AAnimal() : _type("") { std::cout << "Animal costructor called" << std::endl; }

/***  Copy costructor ***/
AAnimal::AAnimal( const AAnimal& other ) { *this = other; }

/*** Assignement operator override ***/
AAnimal& AAnimal::operator=( const AAnimal& other )
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}

/***  Destructor ***/
AAnimal::~AAnimal() { std::cout << "AAnimal destructor called" << std::endl; }

/*** Getters ***/
std::string	AAnimal::getType( void ) const { return _type; }

/*** public methods ***/
void	AAnimal::makeSound( void ) const
{
	std::cout << "..." << std::endl;
}

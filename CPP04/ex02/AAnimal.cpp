#include "AAnimal.h"

/*** costructor ***/
AAnimal::AAnimal() : _type("") { std::cout << "Animal costructor called" << std::endl; }

/*** copy costructor ***/
AAnimal::AAnimal( const AAnimal& other ) { *this = other; }

/*** assignment operator ***/
AAnimal& AAnimal::operator=( const AAnimal& other )
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}

/*** destructor ***/
AAnimal::~AAnimal() { std::cout << "AAnimal destructor called" << std::endl; }

/*** getters ***/
std::string	AAnimal::getType( void ) const { return _type; }

/*** public methods ***/
void	AAnimal::makeSound( void ) const
{
	std::cout << "..." << std::endl;
}

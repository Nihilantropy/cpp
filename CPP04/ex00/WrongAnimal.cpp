#include "WrongAnimal.h"

/*** costructor ***/
WrongAnimal::WrongAnimal() : _type("") { std::cout << "WrongAnimal costructor called" << std::endl; }

/*** copy costructor ***/
WrongAnimal::WrongAnimal( const WrongAnimal& other ) { *this = other; }

/*** assignment operator ***/
WrongAnimal& WrongAnimal::operator=( const WrongAnimal& other )
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal destructor called" << std::endl; }

/*** getters ***/
std::string	WrongAnimal::getType( void ) { return _type; }

/*** public methods ***/
void	WrongAnimal::makeSound( void ) const
{
	std::cout << "..." << std::endl;
}

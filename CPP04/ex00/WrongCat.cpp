#include "WrongCat.h"

/*** costructor ***/
WrongCat::WrongCat()
{
	_type = "WrongCat";
	std::cout << "WrongCat costructor called" << std::endl;
}

/*** copy costructor ***/
WrongCat::WrongCat( const WrongCat& other ) : WrongAnimal(other) {}

/*** assignment operator ***/
WrongCat&	WrongCat::operator=( const WrongCat& other )
{
	if (this != &other)
		WrongAnimal::operator=(other);
	return *this;
}

/*** destructor ***/
WrongCat::~WrongCat() { std::cout << "WrongCat destructor called" << std::endl; }

/*** public methods ***/
void	WrongCat::makeSound( void )  const
{
	std::cout << "Muaoooooooo" << std::endl;
}


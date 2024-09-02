#include <WrongCat.h>

WrongCat::WrongCat()
{
	_type = "WrongCat";
	std::cout << "WrongCat costructor called" << std::endl;
}

WrongCat::~WrongCat() { std::cout << "WrongCat destructor called" << std::endl; }

void	WrongCat::makeSound( void )  const
{
	std::cout << "Muaoooooooo" << std::endl;
}


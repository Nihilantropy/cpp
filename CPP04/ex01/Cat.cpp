#include "Cat.h"

/*** constructor ***/
Cat::Cat()
{
	_type = "Cat";
	std::cout << _type << " constructor called" << std::endl;
	_brain = new Brain();
}

/*** copy constructor with deep copy implementation ***/
Cat::Cat( const Cat& other ) : Animal(other)
{
	_type = other._type;
	std::cout << _type <<  " copy constructor called " << _type <<  " has it's own brain." << std::endl;
	_brain = new Brain(*other._brain);
}

/*** assignment operator override with deep copy implementation ***/
Cat&	Cat::operator=( const Cat& other )
{
	std::cout << _type << " assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		if (_brain)
			delete _brain;
		_brain = new Brain(*other._brain);
		_type = other._type;
	}
	return *this;
}

/*** destructor ***/
Cat::~Cat()
{
	std::cout << _type << " destructor called" << std::endl;
	delete _brain;
}

/*** getters ***/
Brain	*Cat::getBrain( void ) const { return _brain; }

/*** public methods ***/
void	Cat::makeSound( void ) const
{
	std::cout << "Miaoooooooo" << std::endl;
}

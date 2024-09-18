#include "../include/Dog.h"

/***  Costructor ***/
Dog::Dog()
{
	_type = "Dog";
	std::cout << _type << " costructor called" << std::endl;
	_brain = new Brain();
}

/***  Copy costructor with deep copy implementation ***/
Dog::Dog( const Dog& other ) : Animal(other)
{
	_type = other._type;
	std::cout << _type <<  " copy constructor called " << _type <<  " has it's own brain." << std::endl;
	_brain = new Brain(*other._brain);
}

/***  assignment operator override with deep copy implementation ***/
Dog&	Dog::operator=( const Dog& other )
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

/***  Destructor ***/
Dog::~Dog()
{
	std::cout << _type << " destructor called" << std::endl;
	delete _brain;
}

/*** Getters  ***/
Brain	*Dog::getBrain( void ) const { return _brain; }

/*** Public methods ***/
void	Dog::makeSound( void ) const
{
	std::cout << "Bau Bau" << std::endl;
}


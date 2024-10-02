#include "Dog.h"

/*** costructor ***/
Dog::Dog()
{
	_type = "Dog";
	std::cout << _type << " costructor called" << std::endl;
	_brain = new Brain();
}

/*** copy costructor with deep copy implementation ***/
Dog::Dog( const Dog& other ) : AAnimal(other)
{
	_type = other._type;
	std::cout << _type <<  " copy costructor called " << _type <<  " has it's own brain." << std::endl;
	_brain = new Brain(*other._brain);
}

/*** assignment operator override with deep copy implementation ***/
Dog&	Dog::operator=( const Dog& other )
{
	std::cout << _type << " assignment operator called" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		if (_brain)
			delete _brain;
		_brain = new Brain(*other._brain);
		_type = other._type;
	}
	return *this;
}

/*** destructor ***/
Dog::~Dog()
{
	std::cout << _type << " destructor called" << std::endl;
	delete _brain;
}

/*** getters ***/
Brain	*Dog::getBrain( void ) const { return _brain; }

/*** public methods ***/
void	Dog::makeSound( void ) const
{
	std::cout << "Bau Bau" << std::endl;
}


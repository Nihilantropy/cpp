#ifndef ANIMAL_H
#define ANIMAL_H

# include <iostream>

/*** Animal class with virtual Destructor and public method makeSound ***/
class Animal
{
public:
	Animal();
	Animal( const Animal& other );
	Animal& operator=( const Animal& other );
	virtual ~Animal();

	/*** Getters  ***/
	std::string	getType( void ) const;

	/*** public methods ***/
	virtual void	makeSound( void ) const;

protected:
	std::string	_type;
};

#endif

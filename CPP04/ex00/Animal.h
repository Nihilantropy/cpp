#ifndef ANIMAL_H
#define ANIMAL_H

# include <iostream>

class Animal
{
public:
	/*** costructor ***/
	Animal();
	/*** copy costructor ***/
	Animal( const Animal& other );
	/*** assignment operator ***/
	Animal& operator=( const Animal& other );
	/*** destructor ***/
	virtual ~Animal();

	/*** getters  ***/
	std::string	getType( void ) const;

	/*** public methods virtual ***/
	virtual void	makeSound( void ) const;

protected:
	std::string	_type;
};

#endif

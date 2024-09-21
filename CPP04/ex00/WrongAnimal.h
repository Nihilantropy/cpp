#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

# include <iostream>

class WrongAnimal
{
public:
	/*** constructor ***/
	WrongAnimal();
	/*** copy constructor ***/
	WrongAnimal( const WrongAnimal& other );
	/*** assignment operator ***/
	WrongAnimal& operator=( const WrongAnimal& other );
	/*** destructor ***/
	virtual ~WrongAnimal();

	/*** getters ***/
	std::string	getType( void );

	/*** public methods ***/
	void	makeSound( void ) const;

protected:
	std::string	_type;
};

#endif

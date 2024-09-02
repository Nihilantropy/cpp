#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

# include <iostream>

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal( const WrongAnimal& other );
	WrongAnimal& operator=( const WrongAnimal& other );
	virtual ~WrongAnimal();

	/*** getterGetters  ***/
	std::string	getType( void );

	/*** public methods ***/
	void	makeSound( void ) const;

protected:
	std::string	_type;
};

#endif

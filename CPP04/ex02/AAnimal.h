#ifndef AANIMAL_H
#define AANIMAL_H

# include <iostream>

class AAnimal
{
public:
	/*** constructor ***/
	AAnimal();
	/*** copy constructor ***/
	AAnimal( const AAnimal& other );
	/*** assignment operator ***/
	AAnimal& operator=( const AAnimal& other );
	/*** destructor ***/
	virtual ~AAnimal();

	/*** getters ***/
	std::string	getType( void ) const;

	/*** public methods ***/
	/* Pure virtual functions. This make the entire class Abstract (it cannot be instantiated)! */
	virtual void	makeSound( void ) const = 0;

protected:
	std::string	_type;
};

#endif

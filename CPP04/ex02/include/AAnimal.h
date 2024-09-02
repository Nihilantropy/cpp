#ifndef AANIMAL_H
#define AANIMAL_H

# include <iostream>

/*** Animal class with virtual Destructor and public method makeSound ***/
class AAnimal
{
public:
	AAnimal();
	AAnimal( const AAnimal& other );
	AAnimal& operator=( const AAnimal& other );
	virtual ~AAnimal();

	/*** Getters  ***/
	std::string	getType( void ) const;

	/*** public methods ***/
	// Pure virtual functions. This make the entire class Abstract (it cannot be instantiated)!
	virtual void	makeSound( void ) const = 0;

protected:
	std::string	_type;
};

#endif

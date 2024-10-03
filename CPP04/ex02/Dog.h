#ifndef DOG_H
#define Dog_H

# include "AAnimal.h"
# include "Brain.h"

class Dog : public AAnimal
{
public:
	/*** constructor ***/
	Dog();
	/*** copy constructor ***/
	Dog( const Dog& other );
	/*** assignment operator ***/
	Dog& operator=( const Dog& other );
	/*** destructor ***/
	~Dog();

	/*** getters ***/
	Brain*	getBrain( void ) const;

	/*** public methods override ***/
	void	makeSound( void ) const;

private:
	Brain*	_brain;
};

#endif

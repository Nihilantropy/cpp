#ifndef DOG_H
#define Dog_H

# include "Animal.h"
# include "Brain.h"

class Dog : public Animal
{
public:
	/*** costructor ***/
	Dog();
	/*** copy costructor ***/
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

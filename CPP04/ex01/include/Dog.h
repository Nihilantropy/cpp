#ifndef DOG_H
#define Dog_H

# include "../include/Animal.h"
# include "../include/Brain.h"

/*** Dog class with override method makeSound (keyword override is from C++11) ***/
class Dog : public Animal
{
public:
	Dog();
	Dog( const Dog& other );
	Dog& operator=( const Dog& other );
	~Dog();

	/*** Getters  ***/
	Brain*	getBrain( void ) const;

	void	makeSound( void ) const;
private:
	Brain*	_brain;
};

#endif

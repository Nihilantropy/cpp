#ifndef DOG_H
#define Dog_H

# include "Animal.h"

class Dog : public Animal
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

	/*** public methods override ***/
	void	makeSound( void ) const;
};

#endif

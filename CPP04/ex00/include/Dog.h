#ifndef DOG_H
#define Dog_H

# include "Animal.h"

class Dog : public Animal
{
public:
	Dog();
	~Dog();

	void	makeSound( void ) const;
};

#endif

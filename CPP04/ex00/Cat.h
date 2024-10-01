#ifndef CAT_H
#define CAT_H

# include "Animal.h"

class Cat : public Animal
{
public:
	/*** costructor ***/
	Cat();
	/*** copy costructor ***/
	Cat( const Cat& other );
	/*** assignment operator ***/
	Cat& operator=( const Cat& other );
	/*** destructor ***/
	~Cat();

	/*** public methods override ***/
	void	makeSound( void ) const;
};

#endif

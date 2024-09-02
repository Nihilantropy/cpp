#ifndef CAT_H
#define CAT_H

# include "../include/Animal.h"
# include "../include/Brain.h"

/*** Cat class with override method makeSound (keyword override is from C++11) ***/
class Cat : public Animal
{
public:
	Cat();
	Cat( const Cat& other );
	Cat& operator=( const Cat& other );
	~Cat();

	/*** Getters  ***/
	Brain*	getBrain( void ) const;

	/*** public methods ***/
	void	makeSound( void ) const;

private:
	Brain*	_brain;
};

#endif

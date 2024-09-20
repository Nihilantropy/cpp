#ifndef WrongCat_H
#define WrongCat_H

# include "WrongAnimal.h"

class WrongCat : public WrongAnimal
{
public:
	/*** costructor ***/
	WrongCat();
	/*** copy costructor ***/
	WrongCat( const WrongCat& other );
	/*** assignment operator ***/
	WrongCat& operator=( const WrongCat& other );
	/*** destructor ***/
	~WrongCat();

	/*** public methods override ***/
	void	makeSound( void ) const;
};

#endif

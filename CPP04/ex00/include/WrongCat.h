#ifndef WrongCat_H
#define WrongCat_H

# include <WrongAnimal.h>

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	~WrongCat();

	void	makeSound( void ) const;
};

#endif

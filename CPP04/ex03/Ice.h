#ifndef ICE_H
#define ICE_H

# include "AMateria.h"

class Ice : public AMateria
{
public:
	/*** costructor ***/
	Ice();
	/*** copy costructor ***/
	Ice( Ice const & other );
	/*** assignment operator ***/
	Ice& operator=( Ice const & other );
	/*** destructor ***/
	~Ice();

	/*** public methdos ***/
	AMateria*	clone( void ) const;
	void		use( ICharacter& target );
};

#endif

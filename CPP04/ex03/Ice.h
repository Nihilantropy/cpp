#ifndef ICE_H
#define ICE_H

# include "AMateria.h"

class Ice : public AMateria
{
public:
	/*** constructor ***/
	Ice();
	/*** copy constructor ***/
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

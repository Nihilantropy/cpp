#ifndef ICE_H
#define ICE_H

# include "AMateria.h"

class Ice : public AMateria
{
public:
	Ice();
	Ice( Ice const & other );
	Ice& operator=( Ice const & other );
	~Ice();

	/*** Public methdos ***/
	AMateria*	clone( void ) const; // pure override
	void		use( ICharacter& target ); // override
};

#endif

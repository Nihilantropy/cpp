#ifndef ICE_H
#define ICE_H

# include "AMateria.h"

class Ice : public AMateria
{
public:
	Ice();
	Ice( const Ice& other );
	Ice& operator=( const Ice& other );
	~Ice();

	/*** Public methdos ***/
	AMateria*	clone( void ) const; // pure override
	void		use( ICharacter& target ); // override
};

#endif

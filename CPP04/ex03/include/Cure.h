#ifndef CURE_H
#define CURE_H

# include "AMateria.h"

class Cure : public AMateria
{
public:
	Cure();
	Cure( const Cure& other );
	Cure& operator=( const Cure& other );
	~Cure();

	/*** Public methdos ***/
	AMateria*	clone( void ) const; // pure override
	void		use( ICharacter& target ); // override
};

#endif

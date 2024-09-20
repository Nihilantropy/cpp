#ifndef CURE_H
#define CURE_H

# include "AMateria.h"

class Cure : public AMateria
{
public:
	/*** costructor ***/
	Cure();
	/*** copy costructor ***/
	Cure( Cure const & other );
	/*** assignment operator ***/
	Cure& operator=( Cure const & other );
	/*** destructor ***/
	~Cure();

	/*** Public methdos ***/
	AMateria*	clone( void ) const;
	void		use( ICharacter& target );
};

#endif

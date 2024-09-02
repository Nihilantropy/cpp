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

	AMateria*	clone( void ) const;
};

#endif

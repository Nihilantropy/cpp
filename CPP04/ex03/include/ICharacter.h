#ifndef ICHARACTER_H
#define ICHARACTER_H

# include "AMateria.h"

class ICharacter
{
public:
	~ICharacter() {};
	virtual const std::string&	getName( void ) const = 0;
	virtual void				equip( AMateria* m ) = 0;
	virtual void				unequip( int idx ) = 0;
	virtual void				use( int idx, ICharacter& target ) = 0;	
};

#endif

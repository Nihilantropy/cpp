#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "IMateriaSource.h"

# define SLOT_CAP 4

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource( const MateriaSource& other );
	MateriaSource& operator=( const MateriaSource& other );
	~MateriaSource();

	/*** Pure override public methods ***/
	void learnMateria( AMateria* );
	AMateria* createMateria( std::string const & type );

protected:
	AMateria*	_slot[SLOT_CAP];
	void 		clearSlots( void );
};

#endif
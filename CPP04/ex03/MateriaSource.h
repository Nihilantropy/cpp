#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "IMateriaSource.h"

# define SLOT_CAP 4

class MateriaSource : public IMateriaSource
{
public:
	/*** costructor ***/
	MateriaSource();
	/*** copy costructor ***/
	MateriaSource( const MateriaSource& other );
	/*** assignment operator ***/
	MateriaSource& operator=( const MateriaSource& other );
	/*** destructor ***/
	~MateriaSource();

	/*** override IMateriaSource pure methods ***/

	/*** public methods ***/
	void learnMateria( AMateria* );
	AMateria* createMateria( std::string const & type );

protected:
	AMateria*	_slot[SLOT_CAP];

	/*** private methods ***/
	void 		clearSlots( void );
};

#endif
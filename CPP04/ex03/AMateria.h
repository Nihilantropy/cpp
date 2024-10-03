#ifndef AMATERIA_H
#define AMATERIA_H

# include <iostream>
# include <string>
# include "ICharacter.h"

class ICharacter;

class AMateria
{
public:
	/*** constructor ***/
	AMateria( std::string const & type );
	/*** copy constructor ***/
	AMateria( AMateria const & other );
	/*** assignment operator ***/
	AMateria& operator=( AMateria const & other );
	/*** destructor ***/
	virtual ~AMateria();

	/*** getters ***/
	const std::string& getType( void ) const;

	/*** public methdos ***/
	/* pure virtual clone method to make this an abstract class */
	virtual AMateria*	clone( void ) const = 0;
	virtual void		use( ICharacter& target );

protected:
	const std::string	_type;
};

#endif

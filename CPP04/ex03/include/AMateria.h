#ifndef AMATERIA_H
#define AMATERIA_H

# include <iostream>
# include <string>
# include "ICharacter.h"

class ICharacter;

class AMateria
{
public:
	AMateria( std::string const & type );
	AMateria( AMateria const & other );
	AMateria& operator=( AMateria const & other );
	virtual ~AMateria();

	/*** Getters ***/
	const std::string& getType( void ) const;

	/*** Public methdos ***/
	virtual AMateria*	clone( void ) const = 0;
	virtual void		use( ICharacter& target );

protected:
	std::string	_type;
};

#endif

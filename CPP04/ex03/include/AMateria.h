#ifndef AMATERIA_H
#define AMATERIA_H

# include <iostream>
# include <string>

class ICharacter;

class AMateria
{
public:
	AMateria( const std::string& type );
	AMateria( const AMateria& other );
	AMateria& operator=( const AMateria& other );
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

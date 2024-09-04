#ifndef CHARACTER_H
#define CHARACTER_H

# include "ICharacter.h"

class Character : public ICharacter
{
public:
	Character( const std::string& name );
	Character( const Character& other );
	Character& operator=( const Character& other );
	virtual	~Character();

	/*** Pure override ICharacter methods ***/
	const std::string&	getName( void ) const;
	void				equip( AMateria* m);
	void				unequip( int idx );
	void				use( int idx, ICharacter& target );

private:
	std::string	_name;
	AMateria*	_inventory[4];
	void		clearInventory( void );
};

#endif
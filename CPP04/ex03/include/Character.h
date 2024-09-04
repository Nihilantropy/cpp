#ifndef CHARACTER_H
#define CHARACTER_H

# include "ICharacter.h"
# include "AMateria.h"

class Character : public ICharacter
{
public:
	Character( const std::string& name );
	Character( const Character& other );
	Character& operator=( const Character& other );
	virtual	~Character();

	/*** Pure override ICharacter methods ***/

	/** Getters ***/
	std::string const &	getName( void ) const;
	AMateria*	const*	getInventory( void ) const;

	/*** Public methods ***/
	void	equip( AMateria* m);
	void	unequip( int idx );
	void	use( int idx, ICharacter& target );

private:
	std::string	_name;
	AMateria*	_inventory[4];
	AMateria*	_unequipped[100];
	int			_unequippedCount;
	void		clearInventory( void );
};

#endif
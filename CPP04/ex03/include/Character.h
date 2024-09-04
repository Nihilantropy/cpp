#ifndef CHARACTER_H
#define CHARACTER_H

# include "ICharacter.h"
# include "AMateria.h"

# define FLOOR_CAP 10
# define INV_SLOT 4

class Character : public ICharacter
{
public:
	Character( const std::string& name );
	Character( const Character& other );
	Character& operator=( const Character& other );
	virtual	~Character();

	/*** Pure override ICharacter methods ***/

	/*** Getters ***/
	std::string const &	getName( void ) const;
	AMateria*	const*	getInventory( void ) const;
	AMateria*	const*	getFloor( void ) const;

	/*** Public methods ***/
	void	equip( AMateria* m);
	void	unequip( int idx );
	void	use( int idx, ICharacter& target );

	/*** Debug ***/
	void	printInventory( void ) const;
	void	printFloor( void ) const;

private:
	std::string	_name;
	AMateria*	_inventory[4];
	AMateria*	_floor[FLOOR_CAP];
	int			_floorCount;
	void		clearInventory( void );
};

#endif
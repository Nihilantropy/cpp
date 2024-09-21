#ifndef CHARACTER_H
#define CHARACTER_H

# include "ICharacter.h"
# include "AMateria.h"

# define FLOOR_CAP 10
# define INV_SLOT 4

class Character : public ICharacter
{
public:
	/*** constructor ***/
	Character( const std::string& name );
	/*** copy constructor ***/
	Character( const Character& other );
	/*** assignment operator ***/
	Character& operator=( const Character& other );
	/*** destructor ***/
	virtual	~Character();

	/*** override ICharacter pure methods ***/

	/*** getters ***/
	std::string const &	getName( void ) const;
	AMateria*	const*	getInventory( void ) const;
	AMateria*	const*	getFloor( void ) const;

	/*** public methods ***/
	void	equip( AMateria* m);
	void	unequip( int idx );
	void	use( int idx, ICharacter& target );

	/*** debug ***/
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
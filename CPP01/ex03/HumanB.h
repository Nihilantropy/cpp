#ifndef HUMANB_H
#define HUMANB_H

# include "Weapon.h"

class HumanB
{
public:
	/*** costructor ***/
	HumanB( const std::string& name );
	/*** copy costructor ***/
	HumanB( const HumanB& other );
	/*** assignment operator ***/
	HumanB& operator=( const HumanB& other );
	/*** destructor ***/
	~HumanB();

	/*** setter ***/
	void	setWeapon( Weapon& weapon );
	/*** public methods ***/
	void	attack() const;

private:
	std::string	_name;
	Weapon*		_weapon;
};

#endif

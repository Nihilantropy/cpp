#ifndef HUMANB_H
#define HUMANB_H

# include "Weapon.h"

class HumanB
{
public:
	HumanB( const std::string& name );
	~HumanB();

	void	setWeapon( Weapon& weapon );
	void	attack() const;

private:
	std::string	_name;
	Weapon*		_weapon;
};

#endif

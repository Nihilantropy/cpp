#ifndef HUMANA_H
#define HUMANA_H

# include "Weapon.h"

class HumanA
{
public:
	/*** costructor ***/
	HumanA( const std::string& name, Weapon& weapon );
	/*** copy costructor ***/
	HumanA( const HumanA& other );
	/*** assignment operator ***/
	HumanA& operator=( const HumanA& other );
	/*** destructor ***/
	~HumanA();

	/*** public methods ***/
	void	attack() const;

private:
	std::string	_name;
	Weapon&		_weapon;
};

#endif

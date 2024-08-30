#ifndef HUMANA_H
#define HUMANA_H

# include "Weapon.h"

class HumanA
{
public:
	HumanA( const std::string& name, Weapon& weapon );
	~HumanA();

	void	attack() const;

private:
	std::string	_name;
	Weapon&		_weapon;
};

#endif

#include "../include/Character.h"

Character::Character ( const std::string& name ) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character( const Character& other ) : _name(other._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i].clone();
		else
			_inventory[i] = NULL;
	}
}

Character&	Character::operator=( const Character& other )
{
	if (this != &other )
	{
		_name = other._name;
		clearInventory();

		for (int i = 0; i < 4; i++)
		{
			if (other._inventory[i])
				_inventory[i] = other._inventory[i].clone();
			else
				_inventory[i] = NULL;
		}
	}
}

Character::~Character()
{
	clearInventory();
}

std::string const & Character::getName() const { return _name; }
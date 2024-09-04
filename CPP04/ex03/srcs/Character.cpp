#include "../include/Character.h"

Character::Character ( const std::string& name ) : _name(name), _unequippedCount(0)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		_unequipped[i] = NULL;
}

Character::Character( const Character& other ) : _name(other._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character&	Character::operator=( const Character& other )
{
	if (this != &other)
	{
		_name = other._name;

		clearInventory();

		for (int i = 0; i < 4; i++)
		{
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return *this;
}

Character::~Character()
{
	clearInventory();
}

/*** Pure override ICharacter methods ***/

/*** Getters ***/
const 	std::string&	Character::getName( void ) const { return _name; }
AMateria* const*		Character::getInventory( void ) const { return _inventory; }

/*** Private methods ***/
void	Character::clearInventory( void )
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
	for (int i = 0; i < 100; i++)
	{
		if (_unequipped[i])
		{
			delete _unequipped[i];
			_unequipped[i] = NULL;
		}
	}
}

/*** Public methods ***/

bool	checkIfEquipped( Character* character, AMateria* m);

void	Character::equip( AMateria* m )
{
	if (!m)
		return ;
	if (checkIfEquipped( this, m) == true)
	{
		std::cout << "Materis [" << m->getType() << "] is already in the inventory" << std::endl;
		return ;
	}
	
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			std::cout << "Materia " << m->getType() << " added to inventory slot [" << i << "]" << std::endl;
			return ;
		}
	}
	std::cout << "Invetory full. Could not equip " << m->getType() << std::endl;
}

void	Character::unequip( int idx )
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid index. Inventory goes from slot 0 to 3." << std::endl;
		return ;
	}
	if (_inventory[idx])
	{
		std::cout << "Materia " << _inventory[idx]->getType() << " is being unequipped" << std::endl;
		_unequipped[_unequippedCount] = _inventory[idx];
		std::cout << "Unequipped slot " << _unequippedCount << " saved with the unequipped [" << _unequipped[_unequippedCount]->getType() << "] Materia" << std::endl;
		_unequippedCount++;
		_inventory[idx] = NULL;
	}
	else
		std::cout << "No Materia present in slot " << idx << std::endl;
}

void	Character::use( int idx, ICharacter& target )
{
	(void)idx;
	(void)target;
}

bool	checkIfEquipped( Character* character, AMateria* m)
{
	AMateria* const*	inventory;

	inventory = character->getInventory();
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == m)
			return true;
	}
	return false;
}
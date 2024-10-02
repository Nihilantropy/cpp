#include "Character.h"

/*** costructor ***/
Character::Character ( const std::string& name ) : _name(name), _floorCount(0)
{
	for (int i = 0; i < INV_SLOT; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < FLOOR_CAP; i++)
		_floor[i] = NULL;
}

/*** copy costructor ***/
Character::Character( const Character& other ) : _name(other._name), _floorCount(other._floorCount)
{
	for (int i = 0; i < INV_SLOT; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	for (int i = 0; i < FLOOR_CAP; i++)
	{
		if (other._floor[i])
			_floor[i] = other._floor[i]->clone();
		else
			_floor[i] = NULL;
	}
}

/*** assignment operator ***/
Character&	Character::operator=( const Character& other )
{
	if (this != &other)
	{
		clearInventory();

		for (int i = 0; i < INV_SLOT; i++)
		{
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
		for (int i = 0; i < FLOOR_CAP; i++)
		{
			if (other._floor[i])
				_floor[i] = other._floor[i]->clone();
			else
				_floor[i] = NULL;
		}
		_floorCount = other._floorCount;
	}
	return *this;
}

/*** destructor ***/
Character::~Character()
{
	clearInventory();
}

/*** override ICharacter pure methods ***/

/*** getters ***/
const std::string&		Character::getName( void ) const { return _name; }
AMateria* const*		Character::getInventory( void ) const { return _inventory; }
AMateria* const*		Character::getFloor( void ) const { return _floor; }

/*** Private methods ***/
void	Character::clearInventory( void )
{
	for (int i = 0; i < INV_SLOT; i++)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
	for (int i = 0; i < FLOOR_CAP; i++)
	{
		if (_floor[i])
		{
			delete _floor[i];
			_floor[i] = NULL;
		}
	}
	_floorCount = 0;
}

/*** Public methods ***/
bool	checkIfEquipped( Character* character, AMateria* m);
int		checkIfOnthefloor( Character* character, AMateria* m );

void	Character::equip( AMateria* m )
{
	if (!m)
		return ;
	if (checkIfEquipped(this, m) == true)
	{
		std::cout << "Materis [" << m->getType() << "] is already in the inventory" << std::endl;
		return ;
	}
	int	idx = checkIfOnthefloor(this, m);
	if (idx >= 0)
	{
		for (int i = 0; i < INV_SLOT; i++)
		{
			if (_inventory[i] == NULL)
			{
				std::cout << "Materia [" << _floor[idx]->getType() << "] has been picked up from the floor and putted in the inventory at slot " << i << std::endl;
				_inventory[i] = m;
				_floor[idx] = NULL;
				_floorCount--;
				return ;
			}
		}
		std::cout << "Inventory full! Couldn't pick up Materia [" << _floor[idx]->getType() << "] from the floor" << std::endl;
		return ;		
	}
	for (int i = 0; i < INV_SLOT; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			std::cout << "Materia " << m->getType() << " added to inventory slot [" << i << "]" << std::endl;
			return ;
		}
	}
	std::cout << "Invetory full. Could not equip " << m->getType() << ". If Materia wal dynamically allocated, it must have to be freed manually" << std::endl;
}

void	Character::unequip( int idx )
{
	if (idx < 0 || idx >= INV_SLOT)
	{
		std::cout << "Invalid index. Inventory goes from slot 0 to 3." << std::endl;
		return ;
	}
	if (_inventory[idx])
	{
		for (int i = 0; i < FLOOR_CAP; i++)
		{
			if (_floor[i] == NULL)
			{
				_floor[i] = _inventory[idx];
				std::cout << "Materia " << _inventory[idx]->getType() << " has been unequipped and putted on the floor at index " << i << std::endl;
				_inventory[idx] = NULL;
				_floorCount++;
				return ;
			}
		}
		std::cout << "No space left on the floor to unequip Materia " << _inventory[idx]->getType() << std::endl;
	}
	else
		std::cout << "No Materia present in slot " << idx << std::endl;
}

void	Character::use( int idx, ICharacter& target )
{
	if (idx < 0 || idx >= INV_SLOT || !_inventory[idx])
	{
		std::cout << "Invalid index or no materia present in the slot " << idx << std::endl;
		return ;
	}
	_inventory[idx]->use(target);
}

bool	checkIfEquipped( Character* character, AMateria* m )
{
	AMateria* const*	inventory;

	inventory = character->getInventory();
	for (int i = 0; i < INV_SLOT; i++)
	{
		if (inventory[i] == m)
			return true;
	}
	return false;
}

int	checkIfOnthefloor( Character* character, AMateria* m )
{
	AMateria* const*	floor;

	floor = character->getFloor();
	for (int i = 0; i < FLOOR_CAP; i++)
	{
		if (floor[i] == m)
			return i;
	}
	return -1;
}
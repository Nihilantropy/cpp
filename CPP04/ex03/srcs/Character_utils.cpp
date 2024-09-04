#include "Character.h"

void	Character::printInventory( void ) const
{
	std::cout << "\n----------- Print Inventory --------------\n";
	for (int i = 0; i < INV_SLOT; i++)
	{
		if (_inventory[i])
			std::cout << _name << " inventory slot at index " << i << " is: [" << _inventory[i]->getType() << "]" << std::endl;
		else
			std::cout << _name << " inventory slot at index " << i << " is EMPTY" << std::endl;
	}
	std::cout << "\n------------------------------------------\n";
}

void	Character::printFloor( void ) const
{
	std::cout << "\n------------- Print Floor -------------\n";
	for (int i = 0; i < FLOOR_CAP; i++)
	{
		if (_floor[i])
			std::cout << _name << " floor slot at index " << i << " is: [" << _floor[i]->getType() << "]" << std::endl;
		//else
		//	std::cout << _name << " floor slot at index " << i << " is EMPTY" << std::endl;
	}
	std::cout << "\nThere are [" << _floorCount << "] Materias on the floor" << std::endl;
	std::cout << "\n------------------------------------------\n";
}

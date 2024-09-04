# include "Ice.h"
# include "Cure.h"
# include "Character.h"

int main()
{
	std::cout << "\n*** test for initializing, copying and assign AMateria on the stack ***\n" << std::endl;
	
	Ice	ice;

	std::cout << "materia type is: " << ice.getType() << std::endl;

	Ice	ice_copy(ice);

	std::cout << "materia type is: " << ice_copy.getType() << std::endl;

	Ice	ice_a = ice;

	std::cout << "materia type is: " << ice_a.getType() << std::endl;

	std::cout << "\n*** test for initializing, copying and assign AMateria on the heap ***\n" << std::endl;

	Cure*	cure = new Cure();

	std::cout << "materia type is: " << cure->getType() << std::endl;

	Cure	cure_copy(*cure);

	std::cout << "materia type is: " << cure_copy.getType() << std::endl;

	Cure	cure_a = *cure;

	std::cout << "materia type is: " << cure_a.getType() << std::endl;

	std::cout << "\n*** test for AMateria public methods ***\n" << std::endl;

	Character*	bob = new Character("bob");

	std::cout << "Character name is: " << bob->getName() << std::endl;

	ice.use(*bob);
	cure->use(*bob);

	delete cure;

	std::cout << "\n*** test for ICharacter public methods ***\n" << std::endl;

	/*** Character cannot equip materia allocated on the stack (i.e. ice). ***/
	/*** The AMateria copy costructor makes shallow copy, so don't equip them aswell ***/

	AMateria*	cure2 = new Cure();

	//bob->equip(&ice); // uncomment to see the error
	bob->equip(cure2);
	//bob->equip(&cure_copy); // uncomment to see the error
	
	bob->printInventory();
	bob->printFloor();

	std::cout << "\n*** test the inventory surplus and the unequip method ***\n" << std::endl;

	bob->equip(cure2); // Already equippep

	bob->unequip(10); // Invalid input
	bob->unequip(-10); // Invalid input

	bob->unequip(0); // putting the materia on the floor

	
	bob->printInventory();
	bob->printFloor();

	bob->unequip(0); // Nothing in slot 0
	bob->unequip(1); // Nothing in slot 1

	bob->equip(cure2); // Pick up the materia from the floor and equip it

	bob->printInventory();
	bob->printFloor();

	/* Usign the clone method to clone the materia to fill the inventory */
	AMateria*	cure3 = cure2->clone();
	bob->equip(cure3); // Equip at slot 1

	AMateria*	ice2 = new Ice();
	bob->equip(ice2);

	AMateria* ice3 = ice2->clone();
	bob->equip(ice3);

	bob->printInventory();
	bob->printFloor();

	bob->unequip(0);
	bob->unequip(1);
	bob->unequip(2);
	bob->unequip(3);

	bob->printInventory();
	bob->printFloor();

	bob->equip(cure2);
	bob->equip(ice2);
	bob->equip(cure3);
	bob->equip(ice3);

	bob->printInventory();
	bob->printFloor();

	/* Try to put a fifth materia in the inventory */
	AMateria*	cure4 = new Cure();
	bob->equip(cure4);

	delete cure4;

	std::cout << "\n*** test the copy constructor ***\n" << std::endl;

	Character* alex(bob);

	alex->printInventory();
	alex->printFloor();

	alex->unequip(0);
	alex->unequip(1);
	alex->unequip(2);
	alex->unequip(3);

	alex->printInventory();
	alex->printFloor();

	alex->equip(cure2);
	alex->equip(ice2);
	alex->equip(cure3);
	alex->equip(ice3);

	std::cout << "\n*** Test for assignement operetor ***\n" << std::endl;

	Character*	christian = new Character("Christian");

	*christian = *bob;

	christian->printInventory();
	christian->printFloor();

	christian->unequip(0);
	christian->unequip(1);
	christian->unequip(2);
	christian->unequip(3);

	christian->printInventory();
	christian->printFloor();

	christian->equip(cure2);
	christian->equip(ice2);
	christian->equip(cure3);
	christian->equip(ice3);

	christian->printInventory();
	christian->printFloor();

	christian->unequip(0);
	christian->unequip(1);
	christian->unequip(2);
	christian->unequip(3);

	christian->printInventory();
	christian->printFloor();

	std::cout << std::endl;

	delete bob;
	delete christian;
	return 0;
}

#include "../include/Ice.h"
#include "../include/Cure.h"
#include "../include/Character.h"
#include "../include/MateriaSource.h"

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

	Character*	don = new Character("don");

	std::cout << "Character name is: " << don->getName() << std::endl;

	ice.use(*don);
	cure->use(*don);

	delete cure;

	std::cout << "\n*** test for ICharacter public methods ***\n" << std::endl;

	/*** Character cannot equip materia allocated on the stack (i.e. ice). ***/
	/*** The AMateria copy costructor makes shallow copy, so don't equip them aswell ***/

	AMateria*	cure2 = new Cure();

	//don->equip(&ice); // uncomment to see the error
	don->equip(cure2);
	//don->equip(&cure_copy); // uncomment to see the error
	
	don->printInventory();
	don->printFloor();

	std::cout << "\n*** test the inventory surplus and the unequip method ***\n" << std::endl;

	don->equip(cure2); // Already equippep

	don->unequip(10); // Invalid input
	don->unequip(-10); // Invalid input

	don->unequip(0); // putting the materia on the floor

	
	don->printInventory();
	don->printFloor();

	don->unequip(0); // Nothing in slot 0
	don->unequip(1); // Nothing in slot 1

	don->equip(cure2); // Pick up the materia from the floor and equip it

	don->printInventory();
	don->printFloor();

	/* Usign the clone method to clone the materia to fill the inventory */
	AMateria*	cure3 = cure2->clone();
	don->equip(cure3); // Equip at slot 1

	AMateria*	ice2 = new Ice();
	don->equip(ice2);

	AMateria* ice3 = ice2->clone();
	don->equip(ice3);

	don->printInventory();
	don->printFloor();

	don->unequip(0);
	don->unequip(1);
	don->unequip(2);
	don->unequip(3);

	don->printInventory();
	don->printFloor();

	don->equip(cure2);
	don->equip(ice2);
	don->equip(cure3);
	don->equip(ice3);

	don->printInventory();
	don->printFloor();

	/* Try to put a fifth materia in the inventory */
	AMateria*	cure4 = new Cure();
	don->equip(cure4);

	delete cure4;

	std::cout << "\n*** test the copy constructor ***\n" << std::endl;

	Character* alex(don);

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

	std::cout << "\n*** Test for assignment operetor ***\n" << std::endl;

	Character*	christian = new Character("Christian");

	*christian = *don;

	christian->printInventory();
	christian->printFloor();

	christian->unequip(0);
	christian->unequip(1);
	christian->unequip(2);
	christian->unequip(3);

	christian->printInventory();
	christian->printFloor();

	
	/* This prove that the materia passed are not cloned (only specific functions
		call the clone method)
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
	*/
	christian->printInventory();
	christian->printFloor();

	std::cout << std::endl;

	delete don;
	delete christian;

	std::cout << "\n***Testing the subject test ***\n" << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");

	std::cout << std::endl;

	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl;

	delete bob;
	delete me;
	delete src;

	return 0;
}

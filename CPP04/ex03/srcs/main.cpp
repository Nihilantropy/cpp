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

	Ice	ice2 = ice;

	std::cout << "materia type is: " << ice2.getType() << std::endl;

	std::cout << "\n*** test for initializing, copying and assign AMateria on the heap ***\n" << std::endl;

	Cure	*cure = new Cure();

	std::cout << "materia type is: " << cure->getType() << std::endl;

	Cure	cure_copy(*cure);

	std::cout << "materia type is: " << cure_copy.getType() << std::endl;

	Cure	cure2 = *cure;

	std::cout << "materia type is: " << cure2.getType() << std::endl;

	std::cout << "\n*** test for AMateria public methods ***\n" << std::endl;

	Character	*bob = new Character("bob");

	std::cout << "Character name is: " << bob->getName() << std::endl;

	ice.use(*bob);
	cure->use(*bob);

	std::cout << "\n*** test for ICharacter public methods ***\n" << std::endl;

	/*** Character cannot equip materia allocated on the stack (i.e. ice). ***/
	/*** The AMateria copy costructor makes shallow copy, so don't equip them aswell ***/

	//bob->equip(&ice); // uncomment to see the error
	bob->equip(cure);
	//bob->equip(&cure_copy); // uncomment to see the error
	
	std::cout << "\n*** test the inventory surplus and the unequip method ***\n" << std::endl;

	bob->equip(cure);
	bob->unequip(10);
	bob->unequip(-10);
	bob->unequip(0);
	bob->unequip(0);
	bob->equip(cure);

	for (int i = 0; i < 4; i++)
		std::cout << "Bob inventory is: " << bob->getInventory()[i]->getType() << std::endl;


	std::cout << "\n*** test the copy constructor and the assignement operetor of the Character class ***" << std::endl;

	Character* alex = new Character("alex");

	alex = bob;

	for (int i = 0; i < 4; i++)
		std::cout << "Bob inventory is: " << alex->getInventory()[i]->getType() << std::endl;

	//std::cout << "Character name is: " << alex->getName() << std::endl;
	//alex->unequip(1);
	//alex->equip(cure);

	std::cout << std::endl;
	delete bob;
	delete alex;
}

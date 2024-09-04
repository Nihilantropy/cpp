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

	Cure	*cure = new Cure;

	std::cout << "materia type is: " << cure->getType() << std::endl;

	Cure	cure_copy(*cure);

	std::cout << "materia type is: " << cure_copy.getType() << std::endl;

	Cure	cure2 = *cure;

	std::cout << "materia type is: " << cure2.getType() << std::endl;

	delete cure;
}

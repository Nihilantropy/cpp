#include <ScavTrap.h>

int main()
{
	std::cout << "Creating a ScavTrap:" << std::endl;
	ScavTrap	scav("SC4V-TP");

	std::cout << "\nTesting ScavTrap actions:" << std::endl;
	scav.attack("enemy");
	scav.takeDamage(50);
	scav.beRepaired(30);
	scav.guardGate();

	std::cout << "\nCreating a ClapTrap:" << std::endl;
	ClapTrap	clap("CL4P-TP");

	std::cout << "\nTesting ClapTrap actions:" << std::endl;
	clap.attack("enemy");
	clap.takeDamage(5);
	clap.beRepaired(3);

	std::cout << "\nCreating a ScavTrapV to test Virtual behaviors:" << std::endl;
	ScavTrap* scavV = new ScavTrap("FR4-Vx0");

	std::cout << "\nTesting ScavTrap actions:" << std::endl;
	scavV->attack("Antonio");
	scavV->takeDamage(50);
	scavV->beRepaired(10);

	std::cout << "\nTesting virtual behavior with base class pointer:" << std::endl;
	ClapTrap* basePtr = scavV;
	basePtr->attack("Biancaneve");

	std::cout << "\nDeleting ScavTrap using base class pointer:" << std::endl;
	delete basePtr;

	std::cout << "\nEnd of main, destructors will now be called:" << std::endl;
	return 0;
}

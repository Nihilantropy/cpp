#include <DiamondTrap.h>

int main()
{
	std::cout << "Creating a ClapTrap:" << std::endl;
	ClapTrap clap("CL4P-TP");

	std::cout << "\nTesting ClapTrap actions:" << std::endl;
	clap.attack("Gianluca");
	clap.takeDamage(5);
	clap.beRepaired(3);

	std::cout << "\nCreating a ScavTrap:" << std::endl;
	ScavTrap scav("SC4V-TP");

	std::cout << "\nTesting ScavTrap actions:" << std::endl;
	scav.attack("Mario");
	scav.takeDamage(50);
	scav.beRepaired(30);
	scav.guardGate();

	std::cout << "\nCreating a FragTrap:" << std::endl;
	FragTrap frag("FR4-Vx0");

	std::cout << "\nTesting FragTrap actions:" << std::endl;
	frag.attack("Adelaide");
	frag.takeDamage(50);
	frag.beRepaired(10);
	frag.takeDamage(60);
	frag.highFivesGuys();

	std::cout << "\nCreating a FragTrapV to test Virtual behaviors:" << std::endl;
    FragTrap* fragV = new FragTrap("FR4-Vx0");

    std::cout << "\nTesting FragTrap actions:" << std::endl;
    fragV->attack("Antonio");
    fragV->takeDamage(50);
    fragV->beRepaired(10);
    fragV->highFivesGuys();

    std::cout << "\nTesting virtual behavior with base class pointer:" << std::endl;
    ClapTrap* basePtr = fragV;
    basePtr->attack("Biancaneve");

    std::cout << "\nDeleting FragTrap using base class pointer:" << std::endl;
    delete basePtr;

	std::cout << "\nCreating a DiamondTrap:" << std::endl;
	DiamondTrap diamond("DI4M-TP");

	std::cout << "\nTesting DiamondTrap actions:" << std::endl;
	diamond.attack("enemy");
	diamond.takeDamage(80);
	diamond.beRepaired(2000);
	diamond.whoAmI();

	std::cout << "\nCreating a DiamondTrapV to test Virtual behaviors:" << std::endl;
	DiamondTrap* diamondV = new DiamondTrap("DI4-Vx1");

	std::cout << "\nTesting virtual behavior with base class pointer:" << std::endl;
	ClapTrap* basePtrD = diamondV;
	basePtrD->attack("Raperonzolo");

	delete basePtrD;

	std::cout << "\nEnd of main, destructors will now be called:" << std::endl;

	return 0;
}
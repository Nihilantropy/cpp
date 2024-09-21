#include "ClapTrap.h"

int main() {
	ClapTrap claptrap("CL4P-Vx27");

	std::cout << "Initial state:" << std::endl;
	std::cout << "Name: " << claptrap.getName() << std::endl;
	std::cout << "Hit Points: " << claptrap.getHitPoints() << std::endl;
	std::cout << "Energy Points: " << claptrap.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage: " << claptrap.getAttackDamage() << std::endl;

	std::cout << "\nTesting attack:" << std::endl;
	claptrap.attack("enemy1");

	std::cout << "\nTesting takeDamage:" << std::endl;
	claptrap.takeDamage(5);
	claptrap.takeDamage(6);

	std::cout << "\nTesting beRepaired:" << std::endl;
	claptrap.beRepaired(5);
	claptrap.beRepaired(5);

	std::cout << "\nTesting edge cases:" << std::endl;
	claptrap.setEnergyPoints(0);
	claptrap.attack("enemy2");
	claptrap.beRepaired(5);

	claptrap.setHitPoints(0);
	claptrap.takeDamage(5);
	claptrap.attack("enemy3");
	claptrap.setEnergyPoints(10);
	claptrap.beRepaired(5);

	return 0;
}

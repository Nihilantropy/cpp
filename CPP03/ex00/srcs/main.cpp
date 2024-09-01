# include "../include/ClapTrap.h"

int main(int argc, char **argv)
{
	if (argc <= 1)
		return (1);
	ClapTrap	claptrap;

	claptrap.attack( argv[1] );
}

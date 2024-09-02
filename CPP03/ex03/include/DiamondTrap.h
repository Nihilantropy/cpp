#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

# include <ScavTrap.h>
# include <FragTrap.h>

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap( std::string name = "Default DiamondTrap");
	~DiamondTrap();

	void	attack( const std::string& target );
	void	whoAmI( void );

private:
	std::string	_name;
};

#endif

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

# include <iostream>

class ClapTrap
{
public:
	ClapTrap( std::string );
	ClapTrap( const ClapTrap& other );
	ClapTrap& operator=( const ClapTrap& other );
	~ClapTrap();

	int		getHitPoints( void ) const;
	void	setHitPoints( int hitPoints );
	int		getEnergyPoints( void ) const;
	void	setEnergyPoints( int energyPoints );
	int		getAttackDamage( void ) const;
	void	setAttackDamage( int attackDamage );


	void	attack( const std::string& target );
	//void	takeDamage( unsigned int amount );
	//void	beRepaired( unsigned int amount );

private:
	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;
};

#endif

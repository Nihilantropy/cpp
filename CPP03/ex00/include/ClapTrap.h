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

	/*** getter  ***/
	std::string	getName( void ) const;
	int			getHitPoints( void ) const;
	int			getEnergyPoints( void ) const;
	int			getAttackDamage( void ) const;
	
	/*** setter  ***/
	void		setHitPoints( int hitPoints );
	void		setEnergyPoints( int energyPoints );
	void		setAttackDamage( int attackDamage );

	/*** public methods ***/
	void	attack( const std::string& target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );

private:
	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;
};

#endif

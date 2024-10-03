#ifndef CLAPTRAP_H
#define CLAPTRAP_H

# include <iostream>
# include <string>

class ClapTrap
{
public:
	/*** constructor ***/
	ClapTrap( std::string name );
	/*** copy constructor ***/
	ClapTrap( const ClapTrap& other );
	/*** assignment operator ***/
	ClapTrap& operator=( const ClapTrap& other );
	/*** destructor ***/
	~ClapTrap();

	/*** getter ***/
	std::string	getName( void ) const;
	int			getHitPoints( void ) const;
	int			getEnergyPoints( void ) const;
	int			getAttackDamage( void ) const;
	
	/*** setter ***/
	void		setHitPoints( int hitPoints );
	void		setEnergyPoints( int energyPoints );
	void		setAttackDamage( int attackDamage );

	/*** public methods ***/
	void		attack( const std::string& target );
	void		takeDamage( unsigned int amount );
	void		beRepaired( unsigned int amount );

private:
	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;
};

#endif

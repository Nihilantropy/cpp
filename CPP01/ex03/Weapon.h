#ifndef WEAPON_H
#define WEAPON_H

# include <string>
# include <iostream>

class Weapon
{
public:
	/*** constructor ***/
	Weapon( const std::string& type );
	/*** copy constructor ***/
	Weapon( const Weapon& other );
	/*** assignment operator ***/
	Weapon& operator=( const Weapon& other );
	/*** destructor ***/
	~Weapon();

	/*** getter ***/
	const std::string&	getType( void ) const;
	/*** setter ***/
	void				setType( const std::string& newType );

private:
	std::string	_type;
};

#endif

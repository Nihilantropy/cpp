#ifndef WEAPON_H
#define WEAPON_H

# include <string>
# include <iostream>

class Weapon
{
public:
	Weapon( const std::string& type );
	~Weapon();

	const std::string&	getType() const;
	void				setType( const std::string& newType );

private:
	std::string	_type;
};

#endif

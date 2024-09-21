#ifndef HARL_H
#define HARL_H

# include <string>
# include <iostream>

class Harl
{
public:
	/*** constructor ***/
	Harl();
	/*** copy constructor ***/
	Harl( const Harl& other );
	/*** assignment operator ***/
	Harl& operator=( const Harl& other );
	/*** destructor ***/
	~Harl();

	/*** public methods ***/
	void	complain( std::string level );

private:
	/*** private methods ***/
	void	_debug( void );
	void	_info( void );
	void	_warning( void );
	void	_error( void );
};

#endif

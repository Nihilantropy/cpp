#include "Harl.h"

/*** constructor ***/
Harl::Harl() {}

/*** copy constructor ***/
Harl::Harl( const Harl& other ) { *this = other; }

/*** assignment operator ***/
Harl& Harl::operator=( const Harl& other )
{
	(void)other;
	return *this;
}

/*** destructor ***/
Harl::~Harl() {}

/*** public methods ***/
void	Harl::complain( std::string level )
{
	std::string	levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	void	(Harl::*actions[])(void) = {
		&Harl::_debug,
		&Harl::_info,
		&Harl::_warning,
		&Harl::_error
	};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*actions[i])();
			return ;
		}
	}

	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

/*** private methods ***/
void Harl::_debug()
{
	std::cout << "[ DEBUG ]\n"
			<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n\n";
}

void Harl::_info()
{
	std::cout << "[ INFO ]\n"
			<< "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n\n";
}

void Harl::_warning()
{
	std::cout << "[ WARNING ]\n"
			<< "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n\n";
}

void Harl::_error()
{
	std::cout << "[ ERROR ]\n"
			<< "This is unacceptable! I want to speak to the manager now.\n\n";
}

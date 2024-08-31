#include "../include/Harl.h"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::_debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl <<
			"I love having extra bacon for my XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n" << std::endl;
}

void	Harl::_info( void )
{
	std::cout << "[ INFO ]" << std::endl <<
				"I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void	Harl::_warning( void )
{
	std::cout << "[ WARNING ]" << std::endl <<
				"I think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month.\n" << std::endl;
}

void	Harl::_error( void )
{
	std::cout << "[ ERROR ]" << std::endl <<
				"This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

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

	std::cout << "Level not recognized. No complaints." << std::endl;
}


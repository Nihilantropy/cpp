#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

struct Data
{
	/*** struct initialization ***/
	Data();
	/*** struct method ***/
	Data(int n, std::string t);

	/*** struct variables ***/
	int			number;
	std::string	text;
};

#endif
#include "ScalarConverter.h"
#include <cmath>

/***  constructor ***/
ScalarConverter::ScalarConverter() {}

/***  Destructor ***/
ScalarConverter::~ScalarConverter() {}

/*** public methods ***/
void	ScalarConverter::convert( const std::string& literal )
{
	double	value;

	switch (literalType(literal))
	{
		case 0:
			value = static_cast<double>(literal[0]);
			break;
		case 1:
			value = std::strtol(literal.c_str(), NULL, 10);
			break;
		case 2:
			value = std::strtof(literal.c_str(), NULL);
			break;
		case 3:
			value = std::strtod(literal.c_str(), NULL);
			break;
		case -1:
			std::cerr << "Error: invalid literal." << std::endl;
			return;
	}

	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
	
}

/*** private methods ***/

/* check type */
int	ScalarConverter::literalType( const std::string& literal )
{
	if (isChar(literal))
		return 0;
	else if (isInt(literal))
		return 1;
	else if (isFloat(literal))
		return 2;
	else if (isDouble(literal))
		return 3;
	else
		return -1;
}

/*
**	return true if all condition are matched:
**	1) literal length must be 1
**	2) literal must be printable
**	3) literal must not be a digit
*/
bool	ScalarConverter::isChar( const std::string& literal )
{
	return (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]));
}

/*
**	return true if all condition are matched:
**	1) pointer end is used to check where the conversion terminates
**	2) function strtol convert the literal string into a long int in base of 10
**	3) *end != '\0' verify if there are residual char after the converted numeric part
**	4) errno == ERANGE verify if there was an overflow or underflow error
**	5) return true if the converted long in between min and max of int range
*/
bool	ScalarConverter::isInt( const std::string& literal )
{
	char	*end;
	long	num;

	num = std::strtol(literal.c_str(), &end, 10);
	if (*end != '\0' || errno == ERANGE)
		return false;
	return (num >= std::numeric_limits<int>::min() && num <= std::numeric_limits<int>::max());
}

/*
**	return true if all condition are matched:
**	1) pointer end is used to check where the conversion terminates
**	2) function strtof is used to convert literal string to float
**	3) end != 'f' check if there's the 'f' char that indicates
**		the literal float type
**	4) *(end + 1) != '\0' check if there's something else after the 'f' char
**	5) errno == ERANGE verify if there was an overflow or underflow error
**	6) return false if either one of the above condition is matched, otherwise return true
*/
bool	ScalarConverter::isFloat( const std::string& literal )
{
	char	*end;
	
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		return true;

	std::strtof(literal.c_str(), &end);
	if (*end != 'f' || *(end + 1) != '\0' || errno == ERANGE)
		return false;
	return true;
}

/*
**	return true if all condition are matched:
**	1) pointer end is used to check where the conversion terminates
**	2) function strtod is used to convert literal string to double
**	3) *end != '\0' check if there's something else after string convertion
**	4) errno == ERANGE verify if there was an overflow or underflow error
**	5) return false if either one of the above condition is matched, otherwise return true
*/
bool	ScalarConverter::isDouble( const std::string& literal )
{
	char	*end;
	
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		return true;

	std::strtod(literal.c_str(), &end);
	if (*end != '\0' || errno == ERANGE)
		return false;
	return true;
}

/* print type */
void	ScalarConverter::printChar( double value )
{
	std::cout << "char: ";
	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127 || !std::isprint(static_cast<int>(value)))
		std::cout << "impossible" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

void	ScalarConverter::printInt( double value )
{
	std::cout << "int: ";
	if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

void	ScalarConverter::printFloat( double value )
{
	std::cout << "float: ";
	if (std::isnan(value))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(value))
		std::cout << (value > 0 ? "+inff" : "-inff") << std::endl;
	else if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
}

void	ScalarConverter::printDouble( double value )
{
	std::cout << "double: ";
	if (std::isnan(value))
		std::cout << "nan" << std::endl;
	else if (std::isinf(value))
		std::cout << (value > 0 ? "+inf" : "-inf") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}
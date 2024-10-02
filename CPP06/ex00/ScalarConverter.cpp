#include "ScalarConverter.h"
#include <cmath>

/***  costructor ***/
ScalarConverter::ScalarConverter() {}

/***  Destructor ***/
ScalarConverter::~ScalarConverter() {}

/*** public methods ***/
void	ScalarConverter::convert( const std::string& literal )
{
	double		value;
	short		flag;
	int			type;

	value = 0;
	flag = -1;
	type = literalType(literal);
	switch (type)
	{
		case 0:
			flag = 0;
			break;
		case 1:
			flag = 1;
			break;
		case 2:
			flag = 2;
			break;
		case 3:
			value = static_cast<double>(literal[0]);
			break;
		case 4:
			value = std::strtol(literal.c_str(), NULL, 10);
			break;
		case 5:
			value = std::strtof(literal.c_str(), NULL);
			break;
		case 6:
			value = std::strtod(literal.c_str(), NULL);
			break;
		case -1:
			std::cerr << "Error: invalid literal." << std::endl;
			return;
	}

	printChar(value, flag);
	printInt(value, flag);
	printFloat(value, flag);
	printDouble(value, flag);
	
}

/*** private methods ***/

/* check type */
int	ScalarConverter::literalType( const std::string& literal )
{
	if (literal == "+inf" || literal == "inf")
		return 0;
	else if (literal == "-inf")
		return 1;
	else if (literal == "nan")
		return 2;
	else if (isChar(literal))
		return 3;
	else if (isInt(literal))
		return 4;
	else if (isFloat(literal))
		return 5;
	else if (isDouble(literal))
		return 6;
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
**	1) return true if parameter is a pseudoliteral (nan, +inf, -inf)
**	2) pointer end is used to check where the conversion terminates
**	3) function strtof is used to convert literal string to float
**	4) end != 'f' check if there's the 'f' char that indicates
**		the literal float type
**	5) *(end + 1) != '\0' check if there's something else after the 'f' char
**	6) errno == ERANGE verify if there was an overflow or underflow error
**	7) return false if either one of the above condition is matched, otherwise return true
*/
bool	ScalarConverter::isFloat( const std::string& literal )
{
	char	*end;

	if (std::isspace(literal[0]))
		return false;
	std::strtof(literal.c_str(), &end);
	if (*end != 'f' || *(end + 1) != '\0' || errno == ERANGE)
		return false;
	return true;
}

/*
**	return true if all condition are matched:
**	1) return true if parameter is a pseudoliteral (nan, +inf, -inf)
**	2) pointer end is used to check where the conversion terminates
**	3) function strtod is used to convert literal string to double
**	4) *end != '\0' check if there's something else after string convertion
**	5) errno == ERANGE verify if there was an overflow or underflow error
**	6) return false if either one of the above condition is matched, otherwise return true
*/
bool	ScalarConverter::isDouble( const std::string& literal )
{
	char	*end;

	if (std::isspace(literal[0]))
		return false;
	std::strtod(literal.c_str(), &end);
	if (*end != '\0' || errno == ERANGE)
		return false;
	return true;
}

/* print type */

/*
**	handle char print with specific checks wether value
**	is not a number (isnan) and if is infinity (isnif)
**	cast the value to char before print
*/
void	ScalarConverter::printChar( double value, short flag )
{
	std::cout << "char: ";
	if (flag != -1 || (value < 0 || value > 127))
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

/*
**	handle int print with specific checks wether value
**	is not a number (isnan) and if is infinity (isnif)
**	cast the value to int before print
*/
void	ScalarConverter::printInt( double value, short flag )
{
	std::cout << "int: ";
	if (flag != -1 || (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

/*
**	handle float print with specific checks wether value
**	is not a number (isnan) nad if is infinity (isnif)
**	printing nanf, +inf or -inf
**	cast the value to float before print
*/
void	ScalarConverter::printFloat( double value, short flag )
{
	std::cout << "float: ";
	if (flag == 2)
		std::cout << "nanf" << std::endl;
	else if (flag != -1)
		std::cout << (flag == 0 ? "+inff" : "-inff") << std::endl;
	else if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
}

/*
**	handle double print with specific checks wether value
**	is not a number (isnan) nad if is infinity (isnif)
**	printing nan, +inf or -inf
**	cast the value to double before print
*/
void	ScalarConverter::printDouble( double value, short flag )
{
	std::cout << "double: ";
	if (flag == 2)
		std::cout << "nan" << std::endl;
	else if (flag != -1)
		std::cout << (flag == 0 ? "+inf" : "-inf") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}

/***  constructor ***/
ScalarConverter::ScalarConverter() {}

/*** copy costructor ***/
ScalarConverter::ScalarConverter( const ScalarConverter& other ) { *this = other; }

/*** assignment operator ***/
ScalarConverter& ScalarConverter::operator=( const ScalarConverter& other )
{
	(void)other;
	return *this;
}

/***  Destructor ***/
ScalarConverter::~ScalarConverter() {}

#include "ScalarConverter.h"
#include <cmath>

/*** public methods ***/

/*
**	1) Check which literal type was passed as a string parameter.
**	2) Execute switch cases for each type or for special cases: "+inf", "-inf", and "nan".
**	3) If the literal can be converted, store the value in the "value" variable
**		(it's a double because it can contain all other types).
**	4) Print the value. If the flag is active, an edge case occurred, so
**		the output will be formatted accordingly.
*/
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

/* Check the type of the literal */
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
**	Return true if all conditions are met:
**	1) The literal length must be 1.
**	2) The literal must be printable.
**	3) The literal must not be a digit.
*/
bool	ScalarConverter::isChar( const std::string& literal )
{
	return (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]));
}

/*
**	Return true if all conditions are met:
**	1) The end pointer is used to check where the conversion terminates.
**	2) The strtol function converts the literal string into a long int in base 10.
**	3) *end != '\0' checks if there are residual characters after the converted numeric part.
**	4) errno == ERANGE checks if there was an overflow or underflow error.
**	5) Return true if the converted long is within the minimum and maximum range of int.
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
**	Return true if all conditions are met:
**	1) Return true if the parameter is a pseudoliteral (nan, +inf, -inf).
**	2) The end pointer is used to check where the conversion terminates.
**	3) The strtof function is used to convert the literal string to float.
**	4) end != 'f' checks if there's the 'f' character indicating
**		the literal float type.
**	5) *(end + 1) != '\0' checks if there's something else after the 'f' character.
**	6) errno == ERANGE checks if there was an overflow or underflow error.
**	7) Return false if any of the above conditions are met; otherwise, return true.
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
**	Return true if all conditions are met:
**	1) Return true if the parameter is a pseudoliteral (nan, +inf, -inf).
**	2) The end pointer is used to check where the conversion terminates.
**	3) The strtod function is used to convert the literal string to double.
**	4) *end != '\0' checks if there's anything else after the string conversion.
**	5) errno == ERANGE checks if there was an overflow or underflow error.
**	6) Return false if any of the above conditions are met; otherwise, return true.
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
**	Handle char printing with specific checks to see if the value
**	is not a number (isnan) and if it is infinity (isinf).
**	Cast the value to char before printing.
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
**	Handle int printing with specific checks to see if the value
**	is not a number (isnan) and if it is infinity (isinf).
**	Cast the value to int before printing.
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
**	Handle float printing with specific checks to see if the value
**	is not a number (isnan) and if it is infinity (isinf).
**	Print "nanf", "+inf", or "-inf".
**	Cast the value to float before printing.
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
**	Handle double printing with specific checks to see if the value
**	is not a number (isnan) and if it is infinity (isinf).
**	Print "nan", "+inf", or "-inf".
**	Cast the value to double before printing.
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

/*** copy constructor ***/
ScalarConverter::ScalarConverter( const ScalarConverter& other ) { *this = other; }

/*** assignment operator ***/
ScalarConverter& ScalarConverter::operator=( const ScalarConverter& other )
{
	(void)other;
	return *this;
}

/***  Destructor ***/
ScalarConverter::~ScalarConverter() {}

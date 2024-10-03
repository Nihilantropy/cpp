#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cerrno>

class ScalarConverter
{
public:
	/*** public methods ***/
	static void	convert( const std::string& literal );

private:
	/*** private constructor ***/
	ScalarConverter();
	/*** copy constructor ***/
	ScalarConverter( const ScalarConverter& other );
	/*** assignment operator ***/
	ScalarConverter& operator=( const ScalarConverter& other );
	/*** destructor ***/
	~ScalarConverter();

	/*** private methods ***/
	/* check type */
	static int	literalType( const std::string& literal );
	static bool	isChar( const std::string& literal );
	static bool	isInt( const std::string& literal );
	static bool	isFloat( const std::string& literal );
	static bool	isDouble( const std::string& literal );

	/* print type */
	static void	printChar( double value, short flag );
	static void	printInt( double value, short flag );
	static void	printFloat( double value, short flag );
	static void	printDouble( double value, short flag );

};

#endif

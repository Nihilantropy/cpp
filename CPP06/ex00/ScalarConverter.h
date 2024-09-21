#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

# include <iostream>
# include <string>

class ScalarConverter
{
public:
	/*** constructor ***/
	ScalarConverter();
	/*** copy constructor ***/
	ScalarConverter( const ScalarConverter& other );
	/*** assignment operator ***/
	 ScalarConverter& operator=( const ScalarConverter& other );
	/*** destructor ***/
	~ScalarConverter();

	/*** public methods ***/
	void*	convert( const std::string& literal );

private:
	/* Add private members here */
};

#endif

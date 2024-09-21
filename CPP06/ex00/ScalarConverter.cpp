#include "ScalarConverter.h"

/***  constructor ***/
ScalarConverter::ScalarConverter() {}

/***  Copy constructor ***/
ScalarConverter:: ScalarConverter( const ScalarConverter& other ) { *this = other; }

/***  assignment operator override ***/
ScalarConverter& ScalarConverter::operator=( const ScalarConverter& other )
{
	(void)other;
	return *this;
}

/***  Destructor ***/
ScalarConverter::~ScalarConverter() {}

/*** public methods ***/
void*	convert( const std::string& literal )
{
	
}


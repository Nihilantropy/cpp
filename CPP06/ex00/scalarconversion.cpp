#include "ScalarConversion.h"

/***  constructor ***/
ScalarConversion::ScalarConversion() {}

/***  Copy constructor ***/
ScalarConversion::ScalarConversion( const ScalarConversion& other ) { *this = other; }

/***  assignment operator override ***/
ScalarConversion& ScalarConversion::operator=( const ScalarConversion& other )
{
	(void)other;
	return *this;
}

/***  Destructor ***/
ScalarConversion::~ScalarConversion() {}

/*** public methods ***/
void*	convert( const std::string& literal )
{
	
}


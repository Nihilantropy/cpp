#include "../include/ICharacter.h"

/***  Costructor ***/
ICharacter::ICharacter() {}

/***  Copy costructor ***/
ICharacter::ICharacter( const ICharacter& other ) { *this = other; }

/***  Assignement operator override ***/
ICharacter& ICharacter::operator=( const ICharacter& other )
{
	if (this != &other)
	{
		// Assignment operator implementation
	}
	return *this;
}

/***  Destructor ***/
ICharacter::~ICharacter() {}


#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <iostream>
#include <stdint.h>
#include "Data.h"

class Serializer
{
public:
	/*** convert a Data struct pointer into an uintptr_t type ***/
	static uintptr_t	serialize(Data* ptr);

	/*** convert a uintptr_t type into a Data struct pointer ***/
	static Data*		deserialize(uintptr_t raw);

private:
	/*** costructor ***/
	Serializer();
	/*** copy costructor ***/
	Serializer( const Serializer& other );
	/*** assignment operator ***/
	Serializer& operator=( const Serializer& other );
	/*** destructor ***/
	~Serializer();
};

#endif
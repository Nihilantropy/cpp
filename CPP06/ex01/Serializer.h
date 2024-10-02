#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <iostream>
#include "Data.h"

class Serializer
{
public:
	/*** convert a Data struct pointer into an unsigned long type ***/
	static unsigned long	serialize(Data* ptr);

	/*** convert a unsigned long type into a Data struct pointer ***/
	static Data*		deserialize(unsigned long raw);
};

#endif
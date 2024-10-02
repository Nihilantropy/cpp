#include "Serializer.h"

/*** public methods ***/

/*
**	With reinterpret_cast, we can convert a pointer type into another type.
**	This conversion can be dangerous if the types have different memory sizes
**	or if the conversion changes the type's alignment.
**
**	The type uintptr_t, which is defined in <stdint.h>, is an unsigned integer type 
**	that is guaranteed to be large enough to hold a pointer. This makes it safer 
**	to use for converting pointers to integers, as it is designed to be used 
**	for this purpose, regardless of whether the system is 32-bit or 64-bit.
**
**	By using uintptr_t, we ensure that the conversion of a pointer to an integer 
**	and back to a pointer can be done without data loss, making our Serializer 
**	class more robust and portable across different platforms.
**
**	We take the unitptr_t type directly from the C stdint lib, because the
**	uintptr_t type in the c++11 <cstdint> library (that we cannot use)
*/

/*
**	Convert a pointer to Data structure into a uintptr_t type.
**	This allows the pointer to be stored as an integer value.
*/
uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

/*
**	Convert a uintptr_t type back into a pointer to the Data structure.
**	This enables the retrieval of the original pointer.
*/
Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}

/*** private methods ***/

/*** costructor ***/
Serializer::Serializer() {}

/*** copy costructor ***/
Serializer::Serializer( const Serializer& other ) { *this = other; }

/*** assignment operator ***/
Serializer& Serializer::operator=( const Serializer& other )
{
	(void)other;
	return *this;
}

/*** destructor ***/
Serializer::~Serializer() {}

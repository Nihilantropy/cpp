#include "Serializer.h"

/*
**	With reinterpret_cast we can convert a type into another.
**	This can be dangerous if the types have different memory sizes
**	or if the conversion changes the type's alignment.
**
**	C++11 introduced the uintptr_t type, which is guaranteed to be
**	large enough to store a pointer, regardless of whether the system
**	is 32-bit or 64-bit, making the conversion of a pointer to an integer safer.
**
**	In C++98, we can use unsigned long, which may vary in size between
**	32-bit and 64-bit systems. Although unsigned long is not guaranteed
**	to always match the size of a pointer, it is usually large enough to
**	make the conversion (casting) work correctly on most platforms.
*/

/*** convert a Data struct pointer into a unsigned long type ***/
unsigned long Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<unsigned long>(ptr);
}

/*** convert a unsigned long type into a Data struct pointer ***/
Data* Serializer::deserialize(unsigned long raw)
{
    return reinterpret_cast<Data*>(raw);
}

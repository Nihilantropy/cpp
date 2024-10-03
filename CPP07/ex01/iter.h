#ifndef ITER_H
#define ITER_H

#include <iostream>

/*
**	Template function to apply a given function to each element
**	of an array. The template allows for any type of array element
**	and any function that can take that type as an argument.
*/
template <typename T, typename Func>
void	iter(T* array, const size_t& len, const Func& f)
{
	for (size_t i = 0; i < len; i++)
		f(array[i]);
}

#endif
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>  // For std::find
#include <stdexcept>  // For std::exception
#include <iterator>   // For iterator handling

/* Template function that finds an integer in a container of integers */
template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	
	// If element is not found, std::find returns end iterator, so throw an exception
	if (it == container.end())
		throw std::runtime_error("Element not found");

	return it;
}

#endif

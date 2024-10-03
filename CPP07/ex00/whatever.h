#ifndef WHATEVER_H
#define WHATEVER_H

/*	subject quote: 
**	Any function implementation put in a header file (except for function templates)
**	means 0 to the exercise.
*/

/*	
**	template <typename T>
**	Template declaration: 
**	This line defines a template for a function or class using a generic type `T`. 
**	`typename T` means that `T` is a placeholder for a type that will be specified 
**	later when the template is instantiated.
**	It enables us to write 'generic code' that can work with different data types.
*/
template <typename T>

/*
**	Function: swap
**	------------------------
**	The following function template allows swapping two variables of the same type `T`.
**	When the function is called, the actual type (e.g., int, double, etc.) replaces `T`.
**	This template function can be used for any data type that supports assignment.
**	For example, swap<int>(a, b) swaps two integers, and swap<double>(x, y) swaps two doubles.
**
**	Parameters:
**	- `T& a`: A reference to the first element of type `T`.
**	- `T& b`: A reference to the second element of type `T`.
**
**	How it works:
**	1. A temporary variable `temp` of type `T` is used to store the value of `b`.
**	2. The value of `a` is assigned to `b`.
**	3. The temporary value (`temp`) is assigned to `a`, completing the swap.
*/
void	swap(T& a, T& b)
{
	T	temp;

	temp = b;
	b = a;
	a = temp;
}

/*
**	If we want to declare and define another function template,
**	we need to redeclare the template parameter by specifying `template <typename T>`
**	above each function definition, even if the functions are in the same file.
**	This tells the compiler that the function uses the same generic type `T`.
*/
template <typename T>

/*
**	Function: min
**	------------------------
**	Takes two references of the same type `T` and returns the smaller of the two.
**	- If both values are equal, returns the second parameter `b`.
**	- Otherwise, uses the conditional operator to return the smaller of `a` and `b`.
**	
**	Parameters:
**	- T& a: First value to compare.
**	- T& b: Second value to compare.
**
**	Return:
**	- The smaller of the two values (or `b` if they are equal).
*/
const T&	min(const T& a, const T& b)
{
	if (a == b)
		return b;
	return ((a < b) ? a : b);
}

template <typename T>
/*
**	Function: max
**	------------------------
**	Takes two references of the same type `T` and returns the larger of the two.
**	- If both values are equal, returns the second parameter `b`.
**	- Otherwise, uses the conditional operator to return the larger of `a` and `b`.
**	
**	Parameters:
**	- T& a: First value to compare.
**	- T& b: Second value to compare.
**
**	Return:
**	- The larger of the two values (or `b` if they are equal).
*/
const T&	max(const T& a, const T& b)
{
	if (a == b)
		return b;
	return ((a > b) ? a : b);
}

/*
**	This template class allows the creation of generic functions 
**	that operate on different data types without the need for 
**	multiple function declarations.
**
**	You can uncomment the code below and comment out the code above
**	and add "Function<int>" before every 'swap', 'min' and 'max' calls
**	to see that it works exactly the same way.
**
**	Note: This code is provided for educational purposes and 
**	does not adhere to the Orthodox Canonical Form or subject norms 
**	(such as header function initialization).
*/

/*
template <typename T>
class Function
{
public:
	static void	swap( T& a, T& b )
	{
		T	temp;

		temp = b;
		b = a;
		a = temp;
	}
	static T	min( T& a, T& b )
	{
		if (a == b)
			return b;
		return ((a < b) ? a : b);
	}
	static T	max( T& a, T& b )
	{
		if (a == b)
			return b;
		return ((a > b) ? a : b);
	}
};
*/
#endif
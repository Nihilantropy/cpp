#include "mainUtils.h"

/*	generate:
**	1) randomly instantiate one of 3 classe: A B C
**	2) return a pointer to the class
*/
Base*	generate( void )
{
	int	randomValue;

	randomValue = ((rand() % 3));
	std::cout << randomValue << std::endl;
	switch (randomValue)
	{
		case 0: return new A();
		case 1: return new B();
		case 2: return new C();
		default: return NULL;
	}
}

/*	identify (pointer parameter):
**	identify the type of a Base pointer
**	(sinse A, B and C hineryth from Base, with this
**	function we can identify which pointer is of which class)
*/
void	identify( Base* p )
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unkown type" << std::endl;
}

/*	identify (reference parameter):
**	use try-catch block to see if the passed reference
**	corrispond to the the Base type
*/
void	identify( Base& p )
{
	try
	{
		A&	a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (const std::exception& e)
	{
		try
		{
			B&	b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B" << std::endl;
		}
		catch (const std::exception& e)
		{
			try
			{
				C&	c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "C" << std::endl;
			}
			catch (const std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
		}
	}
}

#include "Bureaucrat.h"

int	main()
{
	try
	{
		Bureaucrat bob("Bob", 1);
		std::cout << bob << std::endl;

		bob.decrementGrade();
		std::cout << bob << std::endl;

		Bureaucrat alice("Alice", 1);

		std::cout << alice << std::endl;
		alice.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}

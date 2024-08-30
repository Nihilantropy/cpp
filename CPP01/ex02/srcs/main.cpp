#include <iostream>

int	main()
{
	// Step 1: Define a string variable and initialize it
	std::string	str = "HI THIS IS BRAIN";
	
	// Step 2: Create a pointer to the string
	std::string	*stringPTR = &str;
	
	// Step 3: Create a reference to the string
	std::string	&stringREF = str;
	
	// Print the memory address of the string variable
	std::cout << "Memory address of string variable: " << &str << std::endl;

	// Print the memory address held by stringPTR
	std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
	
	// Print the memory address held by stringREF
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;
	
	// Print the value of the string variable
	std::cout << "Value of string variable: " << str << std::endl;
	
	// Print the value pointed to by stringPTR
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	
	// Print the value referred to by stringREF
	std::cout << "Value referred to by stringREF: " << stringREF << std::endl;

	return 0;
}
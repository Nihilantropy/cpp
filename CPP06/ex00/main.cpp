#include "ScalarConverter.h"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage:\n./convert <literal>" << std::endl;
		return 1;
	}

	std::string literal = argv[1];
	
	try
	{
		ScalarConverter::convert(literal);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
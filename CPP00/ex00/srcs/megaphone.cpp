#include <iostream>
#include <cctype>

static std::string	str_toupper(std::string str);

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for (int i = 1; i < argc; i++)
			std::cout << str_toupper(argv[i]);
		std::cout << std::endl;
	}
	return (0);
}

static std::string	str_toupper(std::string str)
{
	std::string	upper_str;

	for (size_t i = 0; i < str.length(); i++)
		upper_str += (char)toupper(str[i]);
	return (upper_str);
}
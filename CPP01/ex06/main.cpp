#include "Harl.h"

int main(int argc, char **argv)
{
	Harl		harl;
	std::string	level;

	if (argc != 2)
	{
		std::cerr << "[ Usage ]:\n./harlFilter Level\nLevel can be:\nDEBUG\nINFO\nWARNING\nERROR" << std::endl;
		return 1;
	}
	level = argv[1];
	harl.complain(level);

	return 0;
}

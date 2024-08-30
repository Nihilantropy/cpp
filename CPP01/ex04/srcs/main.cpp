#include "../include/FileManipulator.h"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage:" << std::endl << 
					"./sedisforlosers " << "filename " << "s1 " << "s2" << std::endl <<
					"filename is the file where the s1 string will be searched and replaced with s2." << std::endl <<
					"If no substitution happen, no changes will be made." << std::endl << 
					"Otherwise a filename.replace will be generate." << std::endl;
		return 1;
	}
	
	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];

	FileManipulator	file( filename, s1, s2);

	if (!file.processFile())
    {
        std::cerr << "Error processing the file" << std::endl;
        return 1;
    }

	return 0;
}

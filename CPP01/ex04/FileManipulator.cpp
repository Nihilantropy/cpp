#include "FileManipulator.h"

/*** costructor ***/
FileManipulator::FileManipulator( const std::string& filename, const std::string& s1, const std::string& s2 )
	: _filename(filename), _s1(s1), _s2(s2) {}

/*** destructor ***/
FileManipulator::~FileManipulator() {}

/*** public methods ***/
bool	FileManipulator::processFile()
{
	std::ifstream	inFile(_filename.c_str());
	if (!inFile.is_open())
	{
		std::cerr << "Error: Could not open file " << _filename << std::endl;
		return false;
	}

	std::string	content;
	std::string	line;

	while (std::getline(inFile, line))
	{
		content += line;
		if (!inFile.eof())
			content += "\n";
	}
	inFile.close();

	std::string	newContent = replaceOccurrences(content, _s1, _s2);

	std::string		outFile = _filename += ".replace";
	std::ofstream	outFileStream(outFile.c_str());
	if (!outFileStream.is_open())
	{
		std::cerr << "Error: Could not create file " << outFile << std::endl;
		return false;
	}

	outFileStream << newContent;
	outFileStream.close();

	return true;
}

/*** private methods ***/
std::string	FileManipulator::replaceOccurrences( const std::string& content, const std::string& s1, const std::string& s2 )
{
	size_t		i = 0;
	size_t		s1Length = s1.length();
	size_t		foundPos;
	std::string	newContent;

	while (i < content.length())
	{
		foundPos = content.find(s1, i);
		if (foundPos != std::string::npos)
		{
			newContent.append(content, i, foundPos - i);
			newContent.append(s2);
			i = foundPos + s1Length;
		}
		else
		{
			newContent.append(content, i);
			break ;
		}
	}
	return newContent;
}

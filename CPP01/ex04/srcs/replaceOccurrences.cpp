#include "../include/FileManipulator.h"

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
#ifndef FILEMANIPULATOR_H
#define FILEMANIPULATOR_H

# include <string>
# include <iostream>
# include <fstream>

class FileManipulator
{
public:
	/*** costructor ***/
	FileManipulator( const std::string& filename, const std::string& s1, const std::string& s2 );
	/*** destructor ***/
	~FileManipulator();

	/*** public methods ***/
	bool	processFile();

private:
	std::string	replaceOccurrences( const std::string& content, const std::string& s1, const std::string& s2 );
	std::string	_filename;
	std::string	_s1;
	std::string	_s2;
};

#endif

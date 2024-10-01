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
	/*** copy costructor ***/
	FileManipulator( const FileManipulator& other );
	/*** assignment operator ***/
	FileManipulator& operator=( const FileManipulator& other );
	/*** destructor ***/
	~FileManipulator();

	/*** public methods ***/
	bool	processFile( void );

private:
	std::string	_filename;
	std::string	_s1;
	std::string	_s2;
	/*** private methods ***/
	std::string	replaceOccurrences( const std::string& content, const std::string& s1, const std::string& s2 );
};

#endif

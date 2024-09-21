#ifndef SCALARCONVERSION_H
#define SCALARCONVERSION_H

# include <iostream>
# include <string>

class ScalarConversion
{
public:
	/*** constructor ***/
	ScalarConversion();
	/*** copy constructor ***/
	ScalarConversion( const ScalarConversion& other );
	/*** assignment operator ***/
	ScalarConversion& operator=( const ScalarConversion& other );
	/*** destructor ***/
	~ScalarConversion();

	/*** public methods ***/
	void*	convert( const std::string& literal );

private:
	/* Add private members here */
};

#endif

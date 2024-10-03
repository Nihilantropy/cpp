#include "whatever.h"
#include <iostream>
#include <string>

/*
** Overloading the '<', '>' and '==' operators is essential
** to enable comparisons in the 'min' and 'max' functions.
** This allows these functions to determine the ordering 
** of 'Point' objects based on their coordinates.
*/
struct Point
{
	int x, y;
	bool operator<( const Point& other ) const {
		return (x < other.x) || (x == other.x && y < other.y);
	}
	bool operator>( const Point& other ) const {
		return (x > other.x) || (x == other.x && y > other.y);
	}
	bool operator==( const Point& other ) const {
		return (((x == other.x) && (y == other.y)) ? true : false);
	}
};

/* Overload the '<<' operator for Point */
std::ostream& operator<<( std::ostream& os, const Point& p )
{
	os << "(" << p.x << ", " << p.y << ")";
	return os;
}


int main(void)
{
	/* Test with integers */
	std::cout << "Test with integers" << std::endl;
	int a = 2;
	int b = 3;
	std::cout << "before swap\na is " << a << ", b is " << b << std::endl;
	::swap(a, b);
	std::cout << "after swap\na = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::cout << "-----------------------------\n";

	/* Test with doubles */
	std::cout << "Test with double" << std::endl;
	double x = 5.5;
	double y = 3.3;
	std::cout << "before swap\nx is " << x << ", y is " << y << std::endl;
	::swap(x, y);
	std::cout << "after swap\nx = " << x << ", y = " << y << std::endl;
	std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
	std::cout << "max(x, y) = " << ::max(x, y) << std::endl;

	std::cout << "-----------------------------\n";

	/* Test with characters */
	std::cout << "Test with char" << std::endl;
	char char1 = 'z';
	char char2 = 'a';
	std::cout << "before swap\nchar1 is " << char1 << ", char2 is " << char2 << std::endl;
	::swap(char1, char2);
	std::cout << "after swap\nchar1 = " << char1 << ", char2 = " << char2 << std::endl;
	std::cout << "min(char1, char2) = " << ::min(char1, char2) << std::endl;
	std::cout << "max(char1, char2) = " << ::max(char1, char2) << std::endl;

	std::cout << "-----------------------------\n";

	/* Test with strings */
	std::cout << "Test with string" << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "before swap\nstring c is " << c << ", string d is " << d << std::endl;
	::swap(c, d);
	std::cout << "after swap string c = " << c << ", string d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

	std::cout << "-----------------------------\n";

	/* Test with custom types */
	std::cout << "Test with custom types" << std::endl;
	Point p1;
	Point p2;

	p1.x = 1;
	p1.y = 2;
	
	p2.x = 3;
	p2.y = 4;

	std::cout << "before swap\np1 is " << p1 << ", p2 is " << p2 << std::endl; 
	::swap(p1, p2);
	std::cout << "after swap\np1 = " << p1 << ", p2 = "<< p2 << std::endl;
	std::cout << "min(p1, p2) = " << ::min(p1, p2) << std::endl;
	std::cout << "max(p1, p2) = " << ::max(p1, p2) << std::endl;

	std::cout << "-----------------------------\n";

	return 0;
}
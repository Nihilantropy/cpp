#include "Point.h"

/*** constructor ***/
Point::Point() : _x(0), _y(0) {}

/*** constructor with const float parameters ***/
Point::Point( const float x, const float y ) : _x(x), _y(y) {}

/*** copy constructor ***/
Point::Point( const Point& other ) { *this = other; }

/*** assignment operator ***/
Point& Point::operator=( const Point& other )
{
	(void)other;
	return *this;
}

/*** destructor ***/
Point::~Point() {}

/*** getter ***/
Fixed	Point::getX( void ) const { return this->_x; }
Fixed	Point::getY( void ) const { return this->_y; }

#include "Point.h"

Point::Point() : _x(0), _y(0) {}

Point::Point( float const x, float const y ) : _x(x), _y(y) {}

Point::Point( const Point& other ) { *this = other; }

Point& Point::operator=( const Point& other )
{
	(void)other;
	return *this;
}

/*** getters ***/
Fixed	Point::getX( void ) const { return this->_x; }
Fixed	Point::getY( void ) const { return this->_y; }


Point::~Point() {}


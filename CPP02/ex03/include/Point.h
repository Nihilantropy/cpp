#ifndef POINT_H
#define POINT_H

# include "Fixed.h"

class Point
{
public:
	Point();
	Point( float const x, float const y );
	Point( const Point& other );
	Point& operator=( const Point& other );
	~Point();

	Fixed	getX( void ) const;
	Fixed	getY( void ) const;

private:
	Fixed const	_x;
	Fixed const	_y;
};

bool	bsp( Point const a, Point const b, Point const c, Point const point );

#endif

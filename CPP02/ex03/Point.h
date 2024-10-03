#ifndef POINT_H
#define POINT_H

# include "Fixed.h"

class Point
{
public:
	/*** constructor ***/
	Point();
	/*** constructor with const float parameters ***/
	Point( const float x, const float y );
	/*** copy constructor ***/
	Point( const Point& other );
	/*** assignment operator ***/
	Point& operator=( const Point& other );
	/*** destructor ***/
	~Point();

	Fixed	getX( void ) const;
	Fixed	getY( void ) const;

private:
	Fixed const	_x;
	Fixed const	_y;
};

bool	bsp( Point const a, Point const b, Point const c, Point const point );

#endif

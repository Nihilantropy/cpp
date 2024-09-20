#include "Point.h"

const Fixed EPSILON = Fixed(0.0001f);

static Fixed	area( Point const p1, Point const p2, Point const p3 );

/*	bps:
**	if the sum of the subtriangle area is equal to the main triangle area,
**	the point is within the triangle.
**	Use the small espilon value to avoid presicion problems and be more accurate
*/
bool	bsp( Point const a, Point const b, Point const c, Point const point )
{
	Fixed areaABC = area(a, b, c);
	Fixed areaPAB = area(point, a, b);
	Fixed areaPBC = area(point, b, c);
	Fixed areaPCA = area(point, c, a);

	Fixed sumSubAreas = areaPAB + areaPBC + areaPCA;

	 return (sumSubAreas == areaABC) &&
           (areaPAB != Fixed(0)) &&
           (areaPBC != Fixed(0)) &&
           (areaPCA != Fixed(0));
}

/*	area:
**	Given 3 points, calculate the triangle area
*/
static Fixed	area( Point const p1, Point const p2, Point const p3 )
{
	Fixed result = (p1.getX() * (p2.getY() - p3.getY())) +
					(p2.getX() * (p3.getY() - p1.getY())) +
					(p3.getX() * (p1.getY() - p2.getY()));

	if (result < Fixed(0))
		result = result * Fixed(-1);

	return result / Fixed(2);
}
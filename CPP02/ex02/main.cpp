#include <iostream>
#include "../include/Fixed.h"

static int	testMain( void );
static int	subMain( void );

int main( int argc, char **argv )
{
	if (argc == 2 && (std::string)argv[1] == "test")
		testMain();
	else
		subMain();
	return 0;
}

static int	testMain( void )
{
	Fixed a;
	Fixed b(10);
	Fixed c(42.42f);
	Fixed d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;

	Fixed e = b + c;
	Fixed f = b - c;
	Fixed g = b * c;
	Fixed h = b / c;

	std::cout << "b + c = " << e << std::endl;
	std::cout << "b - c = " << f << std::endl;
	std::cout << "b * c = " << g << std::endl;
	std::cout << "b / c = " << h << std::endl;

	std::cout << "a before increment: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a after pre-increment: " << a << std::endl;
	std::cout << "a before post-increment: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a after post-increment: " << a << std::endl;
	std::cout << "a before decrement: " << a << std::endl;
	std::cout << "--a: " << --a << std::endl;
	std::cout << "a after pre-decrement: " << a << std::endl;
	std::cout << "a before post-decrement: " << a << std::endl;
	std::cout << "a--: " << a-- << std::endl;
	std::cout << "a after post-decrement: " << a << std::endl;

	Fixed min = Fixed::min(b, c);
	Fixed max = Fixed::max(b, c);

	std::cout << "Min of b and c: " << min << std::endl;
	std::cout << "Max of b and c: " << max << std::endl;

	return 0;
}

static int	subMain( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}

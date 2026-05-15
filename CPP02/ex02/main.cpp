#include <iostream>
#include "Fixed.hpp"

int main( void ) {

    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed	five(5);
	Fixed	five2(5);
	Fixed	three(3);
	Fixed	negative(-7);
    Fixed	x(10);
	Fixed	y(3);
    Fixed	half(0.5f);
	Fixed	quarter(0.25f);
    Fixed c(5); Fixed d(3);
    Fixed e(0); --e;
    Fixed f; Fixed g;

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;
    
    std::cout << Fixed::max( a, b ) << std::endl;

    std::cout << x / y << std::endl;
    std::cout << (c > d) << std::endl;
    std::cout << e << std::endl;
    std::cout << (f == g) << std::endl;


    std::cout << "5 >  3 : " << (five > three) << std::endl;
    std::cout << "5 <  3 : " << (five < three) << std::endl;
    std::cout << "5 >= 5 : " << (five >= five2) << std::endl;
    std::cout << "5 <= 5 : " << (five <= five2) << std::endl;
    std::cout << "5 == 5 : " << (five == five2) << std::endl;
    std::cout << "5 != 3 : " << (five != three) << std::endl;
    std::cout << "-7 < 0 : " << (negative < a) << std::endl;


    std::cout << "10 + 3   = " << (x + y) << std::endl;
    std::cout << "10 - 3   = " << (x - y) << std::endl;

    std::cout << "0.5 + 0.25 = " << (half + quarter) << std::endl;
    std::cout << "0.5 - 0.25 = " << (half - quarter) << std::endl;

    std::cout << "10 * 3      = " << (x * y) << std::endl;
    std::cout << "10 / 3      = " << (x / y) << std::endl;
    std::cout << "0.5 * 0.5   = " << (half * half) << std::endl;
    std::cout << "2.5 * 4     = " << (Fixed(2.5f) * Fixed(4)) << std::endl;
    std::cout << "1 / 4       = " << (Fixed(1) / Fixed(4)) << std::endl;

    std::cout << "min(10, 3) = " << Fixed::min(x, y) << std::endl;
    std::cout << "max(10, 3) = " << Fixed::max(x, y) << std::endl;

    return 0;
}
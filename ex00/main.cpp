#include "Fixed.hpp"

#include "Fixed.hpp"
#include <iostream>

#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;
	std::cout << c.getRawBits() << std::endl;

	Fixed d;
	d = c;
	std::cout << d.getRawBits() << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}

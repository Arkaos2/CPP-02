#include "Fixed.hpp"

Fixed::Fixed() : _rawbits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _rawbits(other._rawbits){

	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& ref)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &ref)
		this->_rawbits = ref._rawbits;
	return *this;
}
Fixed::~Fixed() {
	std::cout << "Destructeur default called" << std::endl;
};

int Fixed::getRawBits( void ){
	std::cout << "getRawBits member function called" << std::endl;
	return _rawbits;
}

void Fixed::setRawBits(int const raw){
	_rawbits = raw;
}


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

Fixed::Fixed(const int n) : _rawbits(n << _storage) {
	std::cout << "Int constructeur called" << std::endl;
}

Fixed::Fixed(const float f) : _rawbits(roundf(f * (1 << _storage))){
	std::cout << "Float constructeur called" << std::endl;
}

int Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return _rawbits;
}

void Fixed::setRawBits(int const raw){
	_rawbits = raw;
}

int Fixed::toInt() const
{
	return _rawbits >> _storage;
}

float Fixed::toFloat(void) const
{
	return (float)_rawbits / (1 << _storage);
}

std::ostream& operator<<(std::ostream& flux, const Fixed& obj)
{
	flux << obj.toFloat();
	return flux;
}

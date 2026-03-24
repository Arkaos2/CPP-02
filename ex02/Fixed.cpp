#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// ======================= CONSTRUCTEURS =======================
Fixed::Fixed() : _rawbits(0) {
}

Fixed::Fixed(const int n) : _rawbits(n << _storage) {
}

Fixed::Fixed(const float f) : _rawbits(roundf(f * (1 << _storage))) {
}

Fixed::Fixed(const Fixed& other) : _rawbits(other._rawbits) {
}

Fixed& Fixed::operator=(const Fixed& ref) {
	if (this != &ref)
		_rawbits = ref._rawbits;
	return *this;
}

Fixed::~Fixed() {
}

// ======================= GETTER / SETTER =======================
int Fixed::getRawBits(void) const {
	return _rawbits;
}

void Fixed::setRawBits(int const raw) {
	_rawbits = raw;
}

// ======================= CONVERSION =======================
int Fixed::toInt(void) const {
	return _rawbits >> _storage;
}

float Fixed::toFloat(void) const {
	return (float)_rawbits / (1 << _storage);
}

// ======================= OPERATOR << =======================
std::ostream& operator<<(std::ostream& flux, const Fixed& obj) {
	flux << obj.toFloat();
	return flux;
}

// ======================= OPÉRATEURS DE COMPARAISON =======================

bool Fixed::operator>(const Fixed& ref) const
{
	return _rawbits > ref._rawbits;
}

bool Fixed::operator<(const Fixed& ref) const
{
	return _rawbits < ref._rawbits;
}

bool Fixed::operator>=(const Fixed& ref) const
{
	return _rawbits >= ref._rawbits;
}

bool Fixed::operator<=(const Fixed& ref) const
{
	return _rawbits <= ref._rawbits;
}

bool Fixed::operator==(const Fixed& ref) const
{
	return _rawbits == ref._rawbits;
}

bool Fixed::operator!=(const Fixed& ref) const
{
	return _rawbits != ref._rawbits;
}

// ======================= OPÉRATEURS ARITHMÉTIQUES =======================
Fixed Fixed::operator+(const Fixed& ref) const {
	Fixed temp;
	temp.setRawBits(_rawbits + ref.getRawBits());
	return temp;
}

Fixed Fixed::operator-(const Fixed& ref) const {
	Fixed temp;
	temp.setRawBits(_rawbits - ref.getRawBits());
	return temp;
}

Fixed Fixed::operator*(const Fixed& ref) const {
	Fixed temp;
	temp.setRawBits((_rawbits * ref.getRawBits()) >> _storage);
	return temp;
}

Fixed Fixed::operator/(const Fixed& ref) const {
	Fixed temp;
	temp.setRawBits((_rawbits << _storage) / ref.getRawBits());
	return temp;
}

// Pré-incrément
Fixed& Fixed::operator++() {
	_rawbits += 1;
	return *this;
}

// Post-incrément
Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	_rawbits += 1;
	return temp;
}

// Pré-décrément
Fixed& Fixed::operator--() {
	_rawbits -= 1;
	return *this;
}

// Post-décrément
Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	_rawbits -= 1;
	return temp;
}

// ======================= Fonction Compartives =======================

Fixed& Fixed::max(Fixed& num1, Fixed& num2)
{
	if (num1 > num2)
		return num1;
	return num2;
}

const Fixed& Fixed::max(const Fixed& num1, const Fixed& num2)
{
	if (num1 > num2)
		return num1;
	return num2;
}

Fixed& Fixed::min(Fixed& num1, Fixed& num2)
{
	if (num1 < num2)
		return num1;
	return num2;
}

const Fixed& Fixed::min(const Fixed& num1, const Fixed& num2)
{
	if (num1 < num2)
		return num1;
	return num2;
}

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const int n);
		Fixed(const float f);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		bool operator>(const Fixed& obj) const;
		bool operator>=(const Fixed& obj) const;
		bool operator<=(const Fixed& obj) const;
		bool operator<(const Fixed& obj) const;
		bool operator==(const Fixed& obj) const;
		bool operator!=(const Fixed& obj) const;
		Fixed operator+(const Fixed& obj) const;
		Fixed operator*(const Fixed& obj) const;
		Fixed operator-(const Fixed& obj) const;
		Fixed operator/(const Fixed& obj) const;
		Fixed operator++(int);
		Fixed& operator++();
		Fixed operator--(int);
		Fixed& operator--();

		static const Fixed& max(const Fixed& num1, const Fixed& num2);
		static Fixed& max(Fixed& num1, Fixed& num2);
		static const Fixed& min(const Fixed& num1,const Fixed& num2);
		static Fixed& min(Fixed& num1, Fixed& num2);

		private:
			int _rawbits;
			static const int _storage = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif

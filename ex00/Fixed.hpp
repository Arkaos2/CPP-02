#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <string>
# include <cstring>

class Fixed{

	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int _rawbits;
		static int const _storage = 8;
};

#endif

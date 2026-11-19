#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

class Fixed {
    private:
        int _value;
        static const int _bits = 8;

    public:
        Fixed();
        Fixed(const Fixed& source);
        Fixed(const int n);
        Fixed(const float f);
        Fixed& operator=(const Fixed& source);
        Fixed operator+(const Fixed& source);
        Fixed operator-(const Fixed& source);
        Fixed operator*(const Fixed& source);
        Fixed operator/(const Fixed& source);
        bool operator<(const Fixed& source) const;
        bool operator>(const Fixed& source) const;
        bool operator>=(const Fixed& source) const;
        bool operator<=(const Fixed& source) const;
        bool operator==(const Fixed& source) const;
        bool operator!=(const Fixed& source) const;
        Fixed &operator++(void);
        Fixed operator++(int);
        Fixed &operator--(void);
        Fixed operator--(int);
        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
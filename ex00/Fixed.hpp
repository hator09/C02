#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

class Fixed {
    private:
        int _value;
        static const int _bits = 8;

    public:
        Fixed();
        Fixed(const Fixed& source);
        Fixed& operator=(const Fixed& source);
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );

};

#endif
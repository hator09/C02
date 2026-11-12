#include "Fixed.hpp"

Fixed::Fixed(): _value(0){
    std::cout<<"Default constructor called"<<std::endl;
}
Fixed::~Fixed(){
    std::cout<<"Destructor called"<<std::endl;
}
Fixed::Fixed(const Fixed& source){

    std::cout<<"Copy constructor called"<<std::endl;
    *this= source;
}
Fixed& Fixed::operator=(const Fixed& source){  
    std::cout<<"Copy assignment operator called"<<std::endl;
    if (this != &source) {
        this->_value = source._value;
    }
    return *this;
}

int Fixed::getRawBits( void ) const{ 
    std::cout<<"getRawBits member function called"<<std::endl;
    return _value;
}

void Fixed::setRawBits( int const raw ){
    _value = raw;
}
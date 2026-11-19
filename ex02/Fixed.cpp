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
Fixed::Fixed(const int n){
    std::cout<<"Int constructor called"<<std::endl;
    _value = n << _bits;
}
Fixed::Fixed(const float f){
    std::cout<<"Float constructor called"<<std::endl;
    _value = roundf(f * (1 << _bits));
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

float Fixed::toFloat( void ) const{
    return (float)_value / (1 << _bits);
}
int Fixed::toInt( void ) const{
    return _value >> _bits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}

bool Fixed::operator<(const Fixed& source) const{
    return this->_value > source._value;
}
bool Fixed::operator>(const Fixed& source) const{
    return this->_value < source._value;
}
bool Fixed::operator>=(const Fixed& source) const{
    return this->_value >= source._value;
}
bool Fixed::operator<=(const Fixed& source) const{
    return this->_value <= source._value;
}
bool Fixed::operator==(const Fixed& source) const{
    return this->_value == source._value;
}
bool Fixed::operator!=(const Fixed& source) const{
    return this->_value != source._value;
}

Fixed Fixed::operator+(const Fixed& source){
    return Fixed(this->toFloat() + source.toFloat());
}
Fixed Fixed::operator-(const Fixed& source){
    return Fixed(this->toFloat() - source.toFloat());
}
Fixed Fixed::operator*(const Fixed& source){
    return Fixed(this->toFloat() * source.toFloat());
}
Fixed Fixed::operator/(const Fixed& source){
    return Fixed(this->toFloat() / source.toFloat());
}
Fixed &Fixed::operator++(void){
    this->_value++;
    return *this;
}
Fixed Fixed::operator++(int){
    Fixed tmp(*this);
    this->_value++;
    return tmp;

}
Fixed &Fixed::operator--(void){
    this->_value--;
    return *this;
}
Fixed Fixed::operator--(int){
    Fixed tmp(*this);
    this->_value--;
    return tmp;
}
Fixed &Fixed::min(Fixed &a, Fixed &b){
    if(a <= b)
        return a;
    else
        return b;
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b){
    if(a <= b)
        return a;
    else
        return b;
}
Fixed &Fixed::max(Fixed &a, Fixed &b){
    if(a >= b)
        return a;
    else
        return b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b){
    if(a >= b)
        return a;
    else
        return b;
}

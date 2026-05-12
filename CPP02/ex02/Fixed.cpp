#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0) {
}

Fixed::Fixed(const int value) {
    this->_value = value << this->_fractbits;
}

Fixed::Fixed(const float value) {
    this->_value = roundf(value * (1 << this->_fractbits));
}

Fixed::Fixed(const Fixed& other) {
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
}

Fixed::~Fixed(void) {
}

int Fixed::getRawBits(void) const {
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}

float Fixed::toFloat(void) const {
    return (float)this->_value / (1 << this->_fractbits);
}

int Fixed::toInt(void) const {
    return this->_value >> this->_fractbits;
}

//compare
bool	Fixed::operator>(const Fixed &other) const
{
	return this->_value > other._value;
}

bool	Fixed::operator<(const Fixed &other) const
{
	return this->_value < other._value;
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return this->_value >= other._value;
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return this->_value <= other._value;
}

bool	Fixed::operator==(const Fixed &other) const
{
	return this->_value == other._value;
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return this->_value != other._value;
}

// arithmetic
Fixed	Fixed::operator+(const Fixed &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

// Incrément / décrément
Fixed	&Fixed::operator++(void)
{
	++this->_value;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	++this->_value;
	return tmp;
}

Fixed	&Fixed::operator--(void)
{
	--this->_value;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	--this->_value;
	return tmp;
}

// min / max
Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}
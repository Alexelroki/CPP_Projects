#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed( void ): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed& other )
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = other._value;
}

Fixed& Fixed::operator=( const Fixed& other )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_value = other._value;
	}
	return (*this);
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}

Fixed::Fixed( const int value )
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = value << _bits;
}

Fixed::Fixed( const float value )
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << _bits));
}

float	Fixed::toFloat( void ) const
{
	return ((float)this->_value / (1 << _bits));
}

int	Fixed::toInt( void ) const
{
	return (this->_value >> _bits);
}

std::ostream&	operator<<( std::ostream& o, const Fixed& i)
{
	o << i.toFloat();
	return (o);
}

// 1. Comparison operators
bool	Fixed::operator>( const Fixed& other ) const
{
	return (this->_value > other._value);
}

bool	Fixed::operator<( const Fixed& other ) const
{
	return (this->_value < other._value);
}

bool	Fixed::operator>=( const Fixed& other ) const
{
	return (this->_value >= other._value);
}

bool	Fixed::operator<=( const Fixed& other ) const
{
	return (this->_value <= other._value);
}

bool	Fixed::operator==( const Fixed& other ) const
{
	return (this->_value == other._value);
}

bool	Fixed::operator!=( const Fixed& other ) const
{
	return (this->_value != other._value);
}

// 2. Arithmetic operators
Fixed	Fixed::operator+( const Fixed& other ) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-( const Fixed& other ) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*( const Fixed& other ) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/( const Fixed& other ) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

// 3. Increment / Decrement operators
Fixed&	Fixed::operator++( void )
{
	this->_value += 1;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed	temp( *this );
	this->_value += 1;
	return (temp);
}

Fixed&	Fixed::operator--( void )
{
	this->_value -= 1;
	return (*this);
}

Fixed	Fixed::operator--( int )
{
	Fixed	temp( *this );
	this->_value -= 1;
	return (temp);
}

// 4. Static member functions
Fixed&	Fixed::min( Fixed& a, Fixed& b )
{
	return ((a < b) ? a : b);
}

const Fixed&	Fixed::min( const Fixed& a, const Fixed& b )
{
	return ((a < b) ? a : b);
}

Fixed&	Fixed::max( Fixed& a, Fixed& b )
{
	return ((a > b) ? a : b);
}

const Fixed&	Fixed::max( const Fixed& a, const Fixed& b )
{
	return ((a > b) ? a : b);
}


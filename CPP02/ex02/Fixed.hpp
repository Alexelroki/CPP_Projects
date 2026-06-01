#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_bits = 8;
	public:
		// Orhodox Canonical Form
		Fixed( void );
		Fixed( const Fixed& other );
		Fixed&	operator=( const Fixed& other );
		~Fixed( void );

		// Additional Constructors
		Fixed( const int value );
		Fixed( const float value );

		// Getter
		int		getRawBits( void ) const;
		// Setter
		void	setRawBits( int const raw );

		// Conversion Functions
		float	toFloat( void ) const;
		int	toInt( void ) const;

		// 1. Comparison operators
		bool	operator>( const Fixed& other ) const;
		bool	operator<( const Fixed& other ) const;
		bool	operator>=( const Fixed& other ) const;
		bool	operator<=( const Fixed& other ) const;
		bool	operator==( const Fixed& other ) const;
		bool	operator!=( const Fixed& other ) const;

		// 2. Arithmetic operators
		Fixed	operator+( const Fixed& other ) const;
		Fixed	operator-( const Fixed& other ) const;
		Fixed	operator*( const Fixed& other ) const;
		Fixed	operator/( const Fixed& other ) const;

		// 3. Increment / Decrement operators
		Fixed&	operator++( void );
		Fixed	operator++( int );
		Fixed&	operator--( void );
		Fixed	operator--( int );

		// 4. Static member functions
		static Fixed&		min( Fixed& a, Fixed& b );
		static const Fixed&	min( const Fixed& a, const Fixed& b );
		static Fixed&		max( Fixed& a, Fixed& b );
		static const Fixed&	max( const Fixed& a, const Fixed& b );
};

std::ostream&	operator<<( std::ostream& o, const Fixed& i );

#endif

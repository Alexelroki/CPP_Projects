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

		// Functions
		float	toFloat( void ) const;
		int	toInt( void ) const;
};

std::ostream&	operator<<( std::ostream& o, const Fixed& i );

#endif

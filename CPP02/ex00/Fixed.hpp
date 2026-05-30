#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int			_value;
		static const int	_bits = 8;
	public:
		// Orhodox Canonical Form
		Fixed( void );
		Fixed( const Fixed& other );
		Fixed&	operator=( const Fixed& other );
		~Fixed( void );

		// Getter
		int	getRawBits( void ) const;
		// Setter
		void	setRawBits( int const raw );
};

#endif

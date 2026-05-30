#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl
{
	private:
		void	_debug( void ) const;
		void	_info( void ) const;
		void	_warning( void ) const;
		void	_error( void ) const;
	public:
		Harl( void );
		~Harl( void );

		void	complain( const std::string& level ) const;
};

#endif

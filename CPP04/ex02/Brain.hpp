#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
	public:
		Brain( void );
		Brain( const Brain& other );
		Brain&	operator=( const Brain& other );
		virtual ~Brain( void );

	protected:
		std::string	ideas[100];
};

#endif
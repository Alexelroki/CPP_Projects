#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>

class RPN
{
	public:
		// Orthodox Canonical Form
		RPN( void );
		RPN( const RPN& other );
		RPN&			operator=( const RPN& other );
		~RPN( void );

		static void		calculate( const std::string& expr );

	private:
		static bool		isOperator( char c );
		static int		applyOperation( int a, int b, char op );
};

#endif

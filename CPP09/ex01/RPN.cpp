#include "RPN.hpp"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

RPN::RPN( void ) {}

RPN::RPN( const RPN& other )
{
	( void )other;
}

RPN&			RPN::operator=( const RPN& other )
{
	(void)other;
	return (*this);
}

RPN::~RPN( void ) {}

bool		RPN::isOperator( char c )
{
	return ( c == '+' || c == '-' || c == '*' || c == '/' );
}

int		RPN::applyOperation( int a, int b, char op )
{
	switch (op)
	{
		case '+': return ( a + b );
		case '-': return ( a - b );
		case '*': return ( a * b );
		case '/':
			if (b == 0)
				throw std::runtime_error("Error");
			return ( a / b );
		default:
			throw std::runtime_error("Error");
	}
}


void		RPN::calculate( const std::string& expr )
{
	std::stack<int>	s;

	for (size_t i = 0; i < expr.length(); i++)
	{
		char	c = expr[i];

		if (c == ' ' || c == '\t')
			continue ;
		if (std::isdigit(c))
			s.push(c - '0');
		else if (isOperator(c))
		{
			if (s.size() < 2)
				throw std::runtime_error("Error");
			int	b = s.top();
			s.pop();

			int	a = s.top();
			s.pop();

			int	result = applyOperation(a, b, c);
			s.push(result);
		}
		else
			throw std::runtime_error("Error");
	}
	if (s.size() != 1)
		throw std::runtime_error("Error");
	std::cout << s.top() << '\n';
}

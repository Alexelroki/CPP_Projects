#include "RPN.hpp"
#include <iostream>
#include <exception>

int main( int argc, char** argv )
{
	if (argc != 2)
	{
		std::cerr << "Error" << '\n';
		return (1);
	}

	try
	{
		RPN::calculate(argv[1]);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}

	return (0);
}

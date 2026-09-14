#include "PmergeMe.hpp"
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
	{}
	catch (const std::exception& e)
	{}

	return (0);
}

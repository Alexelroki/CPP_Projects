#include "PmergeMe.hpp"
#include <iostream>
#include <exception>

int		main( int argc, char** argv )
{
	if (argc < 2)
	{
		std::cerr << "Error" << '\n';
		return (1);
	}
	try
	{
		PmergeMe	sorter;
		sorter.parse(argc, argv);
		sorter.sort();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error" << '\n';
		return (1);
	}

	return (0);
}

#include "Span.hpp"
#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>

int main()
{
	////////////////////////////////////////////////////////
	std::cout << "=== TEST 1: Subject Example ===" << '\n';
	try
	{
		Span	sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << '\n';
	}

	/////////////////////////////////////////////////////////////////////////////////
	std::cout << "\n=== TEST 2: Scale Test with Range Insertion (15K numbers) ===\n";
	try
	{
		const unsigned int	N = 15000;
		Span	bigSpan(N);

		std::vector<int>	randomNumbers;
		randomNumbers.reserve(N);

		std::srand(static_cast<unsigned int>(std::time(NULL)));
		for (unsigned int i = 0; i < N; ++i)
		{
			randomNumbers.push_back(std::rand());
		}

		bigSpan.addNumber(randomNumbers.begin(), randomNumbers.end());

		std::cout << "Successfully added " << N << " numbers using iterator range.\n";
		std::cout << "Shortest span: " << bigSpan.shortestSpan() << '\n';
		std::cout << "Longest span: " << bigSpan.longestSpan() << '\n';
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << '\n';
	}

	/////////////////////////////////////////////////////////////////////////////////
	std::cout << "\n=== TEST 3: Range Insertion with std::list ===\n";
	try
	{
		std::list<int>	lst;
		lst.push_back(100);
		lst.push_back(200);
		lst.push_back(300);

		Span	lstSpan(5);
		lstSpan.addNumber(lst.begin(), lst.end());

		std::cout << "Successfully added elements from std::list!\n";
		std::cout << "Shortest span: " << lstSpan.shortestSpan() << '\n';
		std::cout << "Longest span: " << lstSpan.longestSpan() << '\n';
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << '\n';
	}

	/////////////////////////////////////////////////////////////
	std::cout << "\n=== TEST 4: OutOfSpaceException Test ===\n";
	try
	{
		Span	smallSpan(2);
		smallSpan.addNumber(10);
		smallSpan.addNumber(20);

		std::cout << "Attempting to add 3rd element to Span(2)..." << '\n';
		smallSpan.addNumber(30); // Debería lanzar OutOfSpaceException
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught expected exception: " << e.what() << '\n';
	}

	///////////////////////////////////////////////////////////////
	std::cout << "\n=== TEST 5: NoSpanException Test ===" << '\n';
	try
	{
		Span	emptySpan(500);
		std::cout << "Attempting shortestSpan() on empty Span..." << '\n';
		emptySpan.shortestSpan(); // This line never runs
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << '\n';
	}

	return (0);
}
#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int	main()
{
	////////////////////////////////////////////////////////////////
	std::cout << "=== TEST 1: Non-const std::vector ===\n";
	try
	{
		std::vector<int>						numbers;
		numbers.push_back(10);
		numbers.push_back(20);
		numbers.push_back(30);

		std::vector<int>::iterator				it = easyfind(numbers, 20);
		std::cout << "Success: Found value " << *it << '\n';

		std::cout << "Searching for non-existing value (99)...\n";
		it = easyfind(numbers, 99);
		std::cout << "Success: Found value " << *it << '\n'; // This line never runs
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << '\n';
	}

	////////////////////////////////////////////////////////////////
	std::cout << "\n=== TEST 2: Const std::vector ===\n";
	try
	{
		std::vector<int>						numbers;
		numbers.push_back(25);
		numbers.push_back(32);
		numbers.push_back(78);
		numbers.pop_back();

		const std::vector<int>					constVec(numbers);
		std::vector<int>::const_iterator		cit = easyfind(constVec, 32);
		std::cout << "Success: Found value " << *cit << '\n';

		std::cout << "Searching for non-existing value (78)...\n";
		cit = easyfind(constVec, 78);
		std::cout << "Success: Found value " << *cit << '\n'; // This line never runs
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << '\n';
	}

	////////////////////////////////////////////////////////////////
	std::cout << "\n=== TEST 3: std::list ===\n";
	try
	{
		std::list<int>							numbersList;
		numbersList.push_back(100);
		numbersList.push_back(200);
		numbersList.push_back(300);

		std::list<int>::iterator				itList = easyfind(numbersList, 200);
		std::cout << "Success: Found value " << *itList << '\n';

		const std::list<int>					emptyList;
		const std::list<int>::const_iterator	itEmptyList = easyfind(emptyList, 200);
		std::cout << "Success: Found value " << *itEmptyList << '\n'; // This line never runs
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << '\n';
	}

	////////////////////////////////////////////////////////////////
	std::cout << "\n=== TEST 4: std::deque ===\n";
	try
	{
		std::deque<int>							deq;
		deq.push_back(2);
		deq.push_back(4);
		deq.push_front(7);

		std::deque<int>::iterator				itDeq = easyfind(deq, 4);
		std::cout << "Success: Found value " << *itDeq << '\n';
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << '\n';
	}

	return (0);
}

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int	main()
{
	////////////////////////////////////////////////////////////////
	std::cout << "=== TEST 1: std::vector ===\n";
	try
	{
		std::vector<int>			numbers;

		numbers.push_back(10);
		numbers.push_back(20);
		numbers.push_back(30);

		std::vector<int>::iterator	it = easyfind(numbers, 20);
		std::cout << "Success: Found value " << *it << '\n';

		std::cout << "Searching for non-existing value (99)...\n";
		easyfind(numbers, 99);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << '\n';
	}

	////////////////////////////////////////////////////////////////
	std::cout << "\n=== TEST 2: std::list ===\n";
	try
	{
		std::list<int>				numbersList;
		numbersList.push_back(100);
		numbersList.push_back(200);
		numbersList.push_back(300);

		std::list<int>::iterator	itList = easyfind(numbersList, 200);
		std::cout << "Success: Found value " << *itList << '\n';

		std::cout << "Searching for non-existing value (99)...\n";
		easyfind(numbersList, 99);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << '\n';
	}

	////////////////////////////////////////////////////////////////
	std::cout << "\n=== TEST 3: Const container ===\n";
	try
	{
		const std::vector<int>		constVec(numbers);
		numbersList.push_back(100);
		numbersList.push_back(200);
		numbersList.push_back(300);

		std::list<int>::iterator	itList = easyfind(numbersList, 200);
		std::cout << "Success: Found value " << *itList << '\n';

		std::cout << "Searching for non-existing value (99)...\n";
		easyfind(numbersList, 99);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << '\n';
	}

	return (0);
}

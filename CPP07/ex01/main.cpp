#include "iter.hpp"
#include <iostream>
#include <string>

// 1. Function template to print elements (const reference)
template <typename T>
void	printElement(const T& elem)
{
	std::cout << elem << ' ';
}

// 2. Regular function to modify elements (non-const reference)
void	incrementInt(int& elem)
{
	elem += 1;
}

int	main(void)
{
	/////////////////////////////////////////////////////////////
	std::cout << "=== TEST 1: Non-const int array ===\n";
	int				intArray[] = {1, 2, 3, 4, 5};
	const size_t	intLen = 5;

	std::cout << "Original array: ";
	::iter(intArray, intLen, printElement<int>);
	std::cout << '\n';

	std::cout << "Incrementing elements using iter...\n";
	::iter(intArray, intLen, incrementInt);

	std::cout << "Incremented array: ";
	::iter(intArray, intLen, printElement<int>);
	std::cout << "\n\n";

	/////////////////////////////////////////////////////////////
	std::cout << "=== TEST 2: Const int array (Read-only check) ===\n";
	const int			constIntArray[] = {10, 20, 30, 40};
	const size_t		constIntLen = 4;

	std::cout << "Const int array: ";
	::iter(constIntArray, constIntLen, printElement<int>);
	std::cout << "\n\n";

	/////////////////////////////////////////////////////////////
	std::cout << "=== TEST 3: Const std::string array ===\n";
	const std::string	strArray[] = {"Hello", "42", "Network"};
	const size_t		strLen = 3;

	std::cout << "String array: ";
	::iter(strArray, strLen, printElement<std::string>);
	std::cout << '\n';

	return (0);
}

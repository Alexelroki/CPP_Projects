#include "Array.hpp"
#include <iostream>
#include <string>

int	main( void )
{
	std::cout << "=== TEST 1: Default Empty Array ===\n";
	Array<int>	emptyArray;
	std::cout << "Empty array size: " << emptyArray.size() << '\n';

	std::cout << "\n=== TEST 2: 5 Integers Array ===\n";
	Array<int>	intArray(5);
	std::cout << "Default values: ";
	for (unsigned int i = 0; i < intArray.size(); i++)
		std::cout << intArray[i] << ' ';
	std::cout << '\n';
	// Modifying elements
	for (unsigned int i = 0; i < intArray.size(); i++)
		intArray[i] = 65 + i;

	std::cout << "\n=== TEST 3: Deep Copy Array ===\n";
	Array<int>	copyIntArray(intArray);
	// Modifying elements
	for (unsigned int i = 0; i < copyIntArray.size(); i++)
		copyIntArray[i] += 1;
	// Comparison
	std::cout << " intArray - copyIntArray\n";
	std::cout << "             (modified)\n";
	std::cout << "  -----         -----\n";
	for (unsigned int i = 0; i < intArray.size(); i++)
	{
		std::cout << i + 1 << ". "
		<< intArray[i]
		<< "     -      "
		<< copyIntArray[i]
		<< '\n';
	}

	std::cout << "\n=== TEST 4: Array of std::string ===\n";
	Array<std::string>	strArray(3);
	strArray[0] = "Hello";
	strArray[1] = "42";
	strArray[2] = "Network";
	for (unsigned int i = 0; i < strArray.size(); i++)
		std::cout << strArray[i] << " ";
	std::cout << '\n';

	std::cout << "\n=== TEST 5: Out of Bounds Exception ===\n";
	try
	{
		std::cout << "Trying to access strArray[3]...\n";
		std::cout << strArray[3] << '\n';
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught Exception: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "Trying to access strArray[-3]...\n";
		std::cout << strArray[-3] << '\n';
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught Exception: " << e.what() << std::endl;
	}

	/*std::cout << "\n=== TEST 6: Const Array Read Access ===\n";
	const Array<int>	constArray(intArray);
	std::cout << "Const Array Element 0: " << constArray[0] << '\n';
	constArray[0] = 42;*/

	return (0);
}

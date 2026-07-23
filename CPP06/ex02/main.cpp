#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>   // std::rand, std::srand
#include <ctime>     // std::time
#include <exception>

// 1. Random Generator
Base*	generate(void)
{
	int	randomChoice = std::rand() % 3;

	if (randomChoice == 0)
		return (new A());
	else if (randomChoice == 1)
		return (new B());
	else
		return (new C());
}

// 2. Identification using POINTER
void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C\n";
}

// 3. Identification using REFERENCE (Using pointers internally is forbidden!)
void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
		return ;
	}
	catch (const std::exception&) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
		return ;
	}
	catch (const std::exception&) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
		return ;
	}
	catch (const std::exception&) {}
}

int	main(void)
{
	// Seed for randomness
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	std::cout << "--- TEST 1: Generation and Destruction ---\n";
	for (int i = 0; i < 5; i++)
	{
		Base*	instance = generate();

		std::cout << "Instance " << i + 1 << " -> Pointer: ";
		identify(instance);

		std::cout << "Instance " << i + 1 << " -> Reference: ";
		identify(*instance);

		// Clean deletion of the resource created with 'new'
		delete instance;
		instance = NULL;
		std::cout << "-----------------------\n";
	}

	return (0);
}

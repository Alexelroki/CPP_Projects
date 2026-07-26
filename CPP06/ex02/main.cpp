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

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C\n";
}

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
		return ;
	}
	catch (const std::exception&)
	{
	}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
		return ;
	}
	catch (const std::exception&)
	{
	}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
		return ;
	}
	catch (const std::exception&)
	{
	}
}

int	main(void)
{
	// Seed for randomness
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	for (int i = 0; i < 5; i++)
	{
		Base*	instance = generate();

		identify(instance);

		identify(*instance);

		delete instance;
		instance = NULL;
	}

	return (0);
}

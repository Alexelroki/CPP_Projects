#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	// =========================================================================
	// 1. MANDATORY SUBJECT TEST (The basic one from the PDF)
	// =========================================================================
	std::cout << "--- SUBJECT BASIC TEST ---" << std::endl;
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		delete j; // Should not create a leak
		delete i;
	}

	// =========================================================================
	// 2. MANDATORY ARRAY TEST (Create, fill half/half, and delete as Animals)
	// =========================================================================
	std::cout << "\n--- SUBJECT ARRAY TEST (10 ANIMALS) ---" << std::endl;
	const int size = 10;
	Animal* animals[size];

	std::cout << "-> Creating animals..." << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << "-------" << i + 1 << "-------" << std::endl;
		if (i < size / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "\n-> Deleting animals directly as Animals..." << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << "-------" << i + 1 << "-------" << std::endl;
		animals[i]->makeSound();
		std::cout << "I am a " << animals[i]->getType() << std::endl;
		delete animals[i];  // Proves virtual destructor works
	}

	// =========================================================================
	// 3. MANDATORY DEEP COPY TEST
	// =========================================================================
	std::cout << "\n--- SUBJECT DEEP COPY TEST ---" << std::endl;
	{
		Dog originalDog;
		{
			// This scope proves that cloneDog gets its OWN independent Brain allocation.
			// If it were a shallow copy, when cloneDog dies here, it would free originalDog's brain,
			// causing a crash/double-free at the end of the outer block.
			Dog cloneDog = originalDog; 
		}
		// originalDog successfully survives here because cloneDog didn't steal/share its brain.
	}

	// =========================================================================
	// 4. EXTRA REQUIRED TESTS
	// =========================================================================
	std::cout << "\n--- EXTRA TEST: WRONG ANIMAL POLYMORPHISM COMPARISON ---" << std::endl;
	{
		std::cout << "-> Creating a WrongCat inside a WrongAnimal* pointer:" << std::endl;
		WrongAnimal* wrong = new WrongCat();

		std::cout << "-> Non-polymorphic sound check: ";
		wrong->makeSound(); // Prints WrongAnimal sound because it lacks 'virtual'

		std::cout << "-> Deallocating via WrongAnimal* pointer:" << std::endl;
		delete wrong; // WrongCat destructor is NEVER called here!
	}

	// =========================================================================
	// ABSTRACT CLASS INSTANTIATION TEST (The core purpose of Ex02)
	// =========================================================================
	// std::cout << "--- ABSTRACT CLASS TEST ---" << std::endl;
	// If you uncomment the line below, the code WILL FAIL to compile.
	// Error: "cannot instantiate abstract class"
	// This proves that Animal is now a pure abstract class as requested.
	
	// const Animal* testAbstract = new Animal();

	return (0);
}
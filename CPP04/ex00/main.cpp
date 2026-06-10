#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{

	std::cout << "\t\t--- CORRECT POLYMORPHISM (VIRTUAL) ---" << std::endl;
	std::cout << "--- Creation ---" << std::endl;
	const	Animal* j = new Dog();
	const	Animal* i = new Cat();
	const	Animal* meta = new Animal();

	std::cout << "\n--- Get Type ---" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;

	std::cout << "\n--- Make Sound ---" << std::endl;
	j->makeSound(); //will output the dog sound!
	i->makeSound();
	meta->makeSound();

	std::cout << "\n--- Delete ---" << std::endl;
	delete j;
	delete i;
	delete meta;

	std::cout << "\t\t--- WRONG POLYMORPHISM (WITHOUT VIRTUAL) ---" << std::endl;
	std::cout << "--- Creation ---" << std::endl;
	const	WrongAnimal* wrong = new WrongCat();

	std::cout << "\n--- Get Type ---" << std::endl;
	std::cout << wrong->getType() << std::endl;

	std::cout << "\n--- Make Sound ---" << std::endl;
	wrong->makeSound();

	std::cout << "\n--- Delete ---" << std::endl;
	delete wrong;

	return (0);
}
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

// I DO NOT RECOMMEND USING THIS MAIN (bad practice / memory leaks)
/*int main(void)
{
    std::cout << "--- 1. MANDATORY SUBJECT TESTS (with Memory Leaks) ---" << std::endl;
    IMateriaSource*	src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter*	me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

	delete bob;
	delete me;
    delete src;

	return 0;
}*/

int main(void)
{
    std::cout << "--- 1. MY OWN TESTS (Responsible Memory Management) ---" << std::endl;

	// Initialize the necessary core objects for our tests
	IMateriaSource*	src = new MateriaSource();
	Character*		bob = new Character("Bob");
	AMateria*		tmp;
	AMateria*		trash; // Use this before unequip() and delete after doing it

	// Responsible approach: main creates, main deletes
	AMateria*		iceTemplate = new Ice();
	src->learnMateria(iceTemplate);
	delete iceTemplate;

	AMateria*		cureTemplate = new Cure();
	src->learnMateria(cureTemplate);
	delete cureTemplate;

	/////////////////////////////////////////////////////////////////////////////

    std::cout << "\n--- 2. DEEP COPY TEST (COPY CONSTRUCTOR) ---" << std::endl;
    // Create an original character and equip a materia
    Character*		original = new Character("Original");
    tmp = src->createMateria("ice");
    original->equip(tmp);

    // Clone it using the copy constructor
    Character* clone = new Character(*original);

    std::cout << "Original uses slot 0: ";
    original->use(0, *bob);
    std::cout << "Clone uses slot 0: ";
    clone->use(0, *bob);

    // Deleting the original must NOT affect the clone if the copy is deep
    std::cout << "-> Deleting original character..." << std::endl;
    delete original;

    std::cout << "Clone uses slot 0 after original's destruction: ";
    clone->use(0, *bob); // If it wasn't a deep copy, this would Segfault
    delete clone;

	/////////////////////////////////////////////////////////////////////////////

    std::cout << "\n--- 3. DEEP COPY TEST (ASSIGNMENT OPERATOR) ---" << std::endl;
	// Create mages
    Character* mage1 = new Character("Mage1");
    tmp = src->createMateria("cure");
    mage1->equip(tmp); // Mage1 starts with Cure

    Character* mage2 = new Character("Mage2");
    tmp = src->createMateria("ice");
    mage2->equip(tmp); // Mage2 starts with Ice

    std::cout << "Before assignment, Mage2 uses slot 0: ";
    mage2->use(0, *bob);

    // Assigning mage1 to mage2. Mage2 must clear its own memory and clone Mage1's Cure
    *mage2 = *mage1;

    std::cout << "After assignment, Mage2 uses slot 0: ";
    mage2->use(0, *bob); // Never unequipped and no memory leaks (;

	/////////////////////////////////////////////////////////////////////////////

	std::cout << "\n--- 4. EDGE CASES (FULL INVENTORY / INVALID INDICES) ---" << std::endl;
    // Using empty or out-of-bounds slots should safely do nothing
    mage1->use(3, *bob);
    mage1->use(-1, *bob);
    mage1->use(4, *bob);

    mage1->unequip(2); // Unequipping an empty slot should safely do nothing
	mage1->use(0, *bob); // Everything works good

	trash = mage1->getMateria(0); // 1. Save the addresses before calling unequip() 
	mage1->unequip(0); // 2. Unequip()
	delete trash; // 3. Avoid Memory Leak (:

    // Final memory cleanup
    delete mage1;
    delete mage2;
	delete src;
	delete bob;

	std::cout << "\n--- PROGRAM FINISHED SUCCESSFULLY ---" << std::endl;

    return (0);
}

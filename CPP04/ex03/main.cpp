#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main(void)
{
    std::cout << "--- 1. MANDATORY SUBJECT TESTS ---" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;
    
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    
    me->use(0, *bob);
    me->use(1, *bob);

    std::cout << "\n--- 2. DEEP COPY TEST (COPY CONSTRUCTOR) ---" << std::endl;
    // Create an original character and equip a materia
    Character* original = new Character("Original");
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

    std::cout << "\n--- 3. DEEP COPY TEST (ASSIGNMENT OPERATOR) ---" << std::endl;
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
    mage2->use(0, *bob);

    std::cout << "\n--- 4. EDGE CASES (FULL INVENTORY / INVALID INDICES) ---" << std::endl;
    // Using empty or out-of-bounds slots should safely do nothing
    mage1->use(3, *bob);
    mage1->use(-1, *bob);
    mage1->use(4, *bob);
    mage1->unequip(2); // Unequipping an empty slot should safely do nothing
	mage1->use(0, *bob); // Everything works good

    // Final memory cleanup
	delete me;
    delete mage1;
    delete mage2;
    delete bob;
    delete src;

	std::cout << "\n--- PROGRAM FINISHED SUCCESSFULLY ---" << std::endl;

    return (0);
}

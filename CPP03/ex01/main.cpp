#include "ScavTrap.hpp"
#include <iostream>

int main( void )
{
	std::cout << "--- ROBOT CREATION ---" << std::endl;
	ScavTrap	scav("SC4V-TP");
	
	std::cout << "\n--- ACTION TEST ---" << std::endl;
	scav.attack("a wild bullymong"); // 1 energy point less (9)
	scav.takeDamage(5);
	scav.beRepaired(3); // 1 energy point less (8)
	scav.guardGate();

	std::cout << "\n--- ENERGY TEST ---" << std::endl;
	// Already spent 2 energy (1 attack + 1 repair). 8 remain.
	for (int i = 1; i <= 48; i++)
	{
		std::cout << i << ". ";
		scav.attack("an enemy");
	}

	std::cout << "\n--- THIS SHOULDN'T WORK ---" << std::endl;
	scav.attack("an enemy");
	scav.beRepaired(100);
	scav.guardGate();

	std::cout << "\n--- DEAD TEST ---" << std::endl;
	ScavTrap	fragile("Porcellaneous");
	fragile.takeDamage(150); // Receives more damage than the life he has

	std::cout << "\n--- THIS SHOULDN'T WORK ---" << std::endl;
	fragile.attack("someone"); // It shouldn't be able to do anything
	fragile.beRepaired(2);
	fragile.guardGate();

	std::cout << "\n---🚨 AUTODESTRUCTION 🚨 ---" << std::endl;
	return (0);
}
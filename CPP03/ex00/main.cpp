#include "ClapTrap.hpp"
#include <iostream>

int main( void )
{
	std::cout << "--- ROBOT CREATION ---" << std::endl;
	ClapTrap	clap("CL4P-TP");
	
	std::cout << "\n--- ACTION TEST ---" << std::endl;
	clap.attack("a wild bullymong"); // 1 energy point less (9)
	clap.takeDamage(5);
	clap.beRepaired(3); // 1 energy point less (8)
	
	std::cout << "\n--- ENERGY TEST ---" << std::endl;
	// Already spent 2 energy (1 attack + 1 repair). 8 remain.
	for (int i = 1; i <= 8; i++)
	{
		std::cout << i << ". ";
		clap.attack("an enemy");
	}

	std::cout << "\n--- THIS SHOULDN'T WORK ---" << std::endl;
	clap.attack("an enemy");
	clap.beRepaired(100);

	std::cout << "\n--- DEAD TEST ---" << std::endl;
	ClapTrap	fragile("Porcellaneous");
	fragile.takeDamage(15); // Receives more damage than the life he has

	std::cout << "\n--- THIS SHOULDN'T WORK ---" << std::endl;
	fragile.attack("someone"); // It shouldn't be able to do anything
	fragile.beRepaired(2);

	std::cout << "\n---🚨 AUTODESTRUCTION 🚨 ---" << std::endl;
	return (0);
}
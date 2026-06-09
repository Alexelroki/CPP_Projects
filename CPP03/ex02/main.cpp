#include "FragTrap.hpp"
#include <iostream>

int	main( void )
{
	std::cout << "--- CREATING FRAGTRAP ---" << std::endl;
	FragTrap	frag("FR4G-TP");
	
	std::cout << "\n--- ACTION TEST ---" << std::endl;
	frag.attack("a wild bullymong"); // 1 energy point less (9)
	frag.takeDamage(5);
	frag.beRepaired(3); // 1 energy point less (8)
	frag.highFivesGuys();

	std::cout << "\n--- ENERGY TEST ---" << std::endl;
	// Already spent 2 energy (1 attack + 1 repair). 8 remain.
	for (int i = 1; i <= 98; i++)
	{
		std::cout << i << ". ";
		frag.attack("an enemy");
	}

	std::cout << "\n--- THIS SHOULDN'T WORK ---" << std::endl;
	frag.attack("an enemy");
	frag.beRepaired(100);
	frag.highFivesGuys();

	std::cout << "\n--- DEAD TEST ---" << std::endl;
	FragTrap	fragile("Porcellaneous");
	fragile.takeDamage(150); // Receives more damage than the life he has

	std::cout << "\n--- THIS SHOULDN'T WORK ---" << std::endl;
	fragile.attack("someone"); // It shouldn't be able to do anything
	fragile.beRepaired(2);
	fragile.highFivesGuys();

	std::cout << "\n--- DESTRUCTION CHAIN ---" << std::endl;
	return (0);
}

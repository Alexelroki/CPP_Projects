#include "FragTrap.hpp"
#include <iostream>

int main( void )
{
	std::cout << "--- CREATING FRAGTRAP ---" << std::endl;
	FragTrap frag("FR4G-TP");

	std::cout << "\n--- ACTION AND ATTACK TEST ---" << std::endl;
	frag.attack("a dangerous bandit"); // Uses ClapTrap's attack
	frag.takeDamage(40);
	frag.beRepaired(20);

	std::cout << "\n--- SPECIAL ABILITY TEST ---" << std::endl;
	frag.highFivesGuys();

	std::cout << "\n--- DESTRUCTION CHAIN ---" << std::endl;
	return (0);
}
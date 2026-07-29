#include "DiamondTrap.hpp"
#include <iostream>

// ClapTrap's name -> [name + "_clap_name"], ScavTrap and FragTraps inherit the ClapTrap's name
// Hit Points -> FragTrap -> 100
// Energy Points -> ScavTrap -> 50
// Attack Damage -> FragTrap -> 30
// attack() -> ScavTrap

int main( void )
{
	std::cout << "--- CREATING DIAMONDTRAP ---" << std::endl;
	DiamondTrap	diamond("DI4M-TP");
	DiamondTrap	copy1("C0PY-TP");

	std::cout << "\n--- ACTION AND ATTACK TEST ---" << std::endl;
	diamond.attack("a dangerous bandit"); // Uses ScavTrap's attack
	diamond.guardGate(); // Uses ScavTrap's function
	diamond.takeDamage(40); // Uses ClapTrap's function
	diamond.beRepaired(20); // Uses ClapTrap's function
	diamond.whoAmI();
	diamond.highFivesGuys();

	std::cout << "\n--- ASSIGNMENT AND COPY TEST ---" << std::endl;

	std::cout << "1. \n";
	copy1.whoAmI();
	copy1 = diamond;
	copy1.takeDamage(1);
	copy1.whoAmI();

	std::cout << "2. \n";
	DiamondTrap	copy2(diamond);
	copy2.takeDamage(1);
	copy2.whoAmI();

	std::cout << "\n--- ENERGY TEST ---" << std::endl;
	DiamondTrap	energytest("EN3RGY-TP");
	for (int i = 1; i <= 50; i++)
	{
		std::cout << i << ". ";
		energytest.attack("a dangerous bandit"); // 50 energy points consumed
	}
	energytest.attack("a dangerous bandit"); // No energy to attack*/

	std::cout << "\n--- DESTRUCTION CHAIN ---" << std::endl;
	return (0);
}
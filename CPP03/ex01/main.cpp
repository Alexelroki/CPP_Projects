#include "ScavTrap.hpp"
#include <iostream>

int main( void )
{
	std::cout << "--- SCAVTRAP CREATION ---" << std::endl;
	ScavTrap scav("SC4V-TP");

	std::cout << "\n--- ACTION AND ATTACK TEST ---" << std::endl;
	scav.attack("an aggressive psycho");
	scav.takeDamage(30);
	scav.beRepaired(15);

	std::cout << "\n--- SPECIAL ABILITY TEST ---" << std::endl;
	scav.guardGate();

	std::cout << "\n--- DESTRUCTION CHAIN ---" << std::endl;
	return (0);
}
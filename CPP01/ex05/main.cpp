#include "Harl.hpp"
#include <iostream>

int	main( void )
{
	Harl	harl;

	std::cout << "              --- [ Harl tests ] ---\n" << std::endl;

	harl.complain("DEBUG");
	std::cout << std::endl;

	harl.complain("INFO");
	std::cout << std::endl;

	harl.complain("WARNING");
	std::cout << std::endl;

	harl.complain("ERROR");
	std::cout << std::endl;

	harl.complain("I'M CALLING THE POLICE");
	std::cout << std::endl;

	return (0);
}

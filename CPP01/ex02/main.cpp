#include <iostream>
#include <string>

int	main( void )
{
	std::string	hi = "HI THIS IS BRAIN";
	std::string*	stringPTR = &hi;
	std::string&	stringREF = hi;

	std::cout << "Memory address of the string variable: " << &hi << std::endl;
	std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

	std::cout << "\nValue of the string variable: " << hi << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

}

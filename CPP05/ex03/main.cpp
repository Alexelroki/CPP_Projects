#include <ctime>
#include <cstdlib>
#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
	std::srand(std::time(NULL)); // Seed for random robotomy request form
	Intern	myke;
	AForm*	randomForm = NULL;

	std::cout << "--- Test 1: Succesful Form Creation ---\n";
	try
	{
		randomForm = myke.makeForm("robotomy request", "Bender");
		if (randomForm)
		{
			std::cout << *randomForm << "\n";
			delete randomForm;
			randomForm = NULL;
		}

		randomForm = myke.makeForm("shrubbery creation", "Leela");
		if (randomForm)
		{
			std::cout << *randomForm << "\n";
			delete randomForm;
			randomForm = NULL;
		}

		randomForm = myke.makeForm("presidential pardon", "Fry");
		if (randomForm)
		{
			std::cout << *randomForm << "\n";
			delete randomForm;
			randomForm = NULL;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught during creation: " << e.what() << "\n";
		if (randomForm)
		{
			delete randomForm;
			randomForm = NULL;
		}
	}

	std::cout << "--- Test 2: Unknown Form Creation ---\n";
	try
	{
		randomForm = myke.makeForm("invalid request", "Hermes");
		if (randomForm == NULL)
			std::cout << "Intern safely returned NULL for unknown form.\n";
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << "\n";
	}

	return (0);
}

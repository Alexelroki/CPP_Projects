#include "Bureaucrat.hpp"

int main()
{
	//////////////////////////////////////////////////////////////////////////////////////
	std::cout << "--- Test 1: Creating a valid Bureaucrat ---" << std::endl;
	try
	{
		// ✅ Grade by default: 150.
		Bureaucrat	defaultGuy;
		std::cout << "1. " << defaultGuy << std::endl;

		// ✅ After increment: 149.
		defaultGuy.incrementGrade();
		std::cout << "2. " << "After increment: " << defaultGuy << std::endl;

		// ✅ Copy constructor
		Bureaucrat	copyGuy(defaultGuy);
		std::cout << "3. ...Copying default bureaucrat before decrement his value" << std::endl;

		// ✅ After decrement: 150.
		defaultGuy.decrementGrade();
		std::cout << "4. After decrement: " << defaultGuy << std::endl;

		// ✅ Showing copied bureaucrat conserves the value before decrement
		std::cout << "5. Default's bureaucrat copied:" << copyGuy << std::endl;

		// ❌ Trying to decrement one more time: should not work.
		defaultGuy.decrementGrade();
		std::cout << "00. This line will never be reached" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "6. Exception caught: " << e.what() << std::endl;
	}

	//////////////////////////////////////////////////////////////////////////////////////
	std::cout << "\n--- Test 2: Creating an invalid Bureaucrat (Too High)---" << std::endl;
	try
	{
		// ❌ Trying to create a Bureaucrat with a too high grade
		Bureaucrat	crashGuy("Crash", 0);
		std::cout << "99. " << crashGuy << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "1. Exception caught: " << e.what() << std::endl;
	}

	return (0);
}

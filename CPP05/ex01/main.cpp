#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	//////////////////////////////////////////////////////////////////////////////////////
	std::cout << "--- Test 1: Creating a valid Form and signing it ---" << std::endl;
	try
	{
		// ✅ Creating a bureaucrat and a standard form
		Bureaucrat	boss("Alex", 10);
		Form		taxForm("Tax Return Form", 45, 30);

		std::cout << "1. " << boss << std::endl;
		std::cout << "2. " << taxForm << std::endl;

		// ✅ Bureaucrat signs the form successfully
		std::cout << "3. Attempting to sign the form..." << std::endl;
		boss.signForm(taxForm);

		// ✅ Showing the form state after signing
		std::cout << "4. Post-signing form state: " << taxForm << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "XX. Exception caught (should not happen here): " << e.what() << std::endl;
	}

	//////////////////////////////////////////////////////////////////////////////////////
	std::cout << "\n--- Test 2: Bureaucrat grade too low to sign ---" << std::endl;
	try
	{
		// ❌ Bureaucrat has grade 100, but form requires grade 50 to be signed
		Bureaucrat  lowGuy("Low Level Kevin", 100);
		Form        topSecretForm("Top Secret Document", 50, 20);

		std::cout << "1. " << lowGuy << std::endl;
		std::cout << "2. " << topSecretForm << std::endl;

		// ❌ This will internally catch the Form::GradeTooLowException via signForm
		std::cout << "3. Kevin tries to sign something above his paygrade..." << std::endl;
		lowGuy.signForm(topSecretForm);

		// ❌ This direct action will explicitly throw and jump to the catch block
		std::cout << "4. Forcing direct form.beSigned() call..." << std::endl;
		topSecretForm.beSigned(lowGuy);
		
		std::cout << "00. This line will never be reached" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "5. Exception caught: " << e.what() << std::endl;
	}

	//////////////////////////////////////////////////////////////////////////////////////
	std::cout << "\n--- Test 3: Creating an invalid Form (Grade Too High) ---" << std::endl;
	try
	{
		// ❌ Trying to create a Form with an invalid sign grade (0)
		Form	illegalForm("Illegal Form", 0, 50);
		std::cout << "99. " << illegalForm << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "1. Exception caught: " << e.what() << std::endl;
	}

	return (0);
}

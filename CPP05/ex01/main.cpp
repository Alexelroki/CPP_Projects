#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	//////////////////////////////////////////////////////////////////////////////////////
	std::cout << "--- Test 1: Creating a valid Form and signing it ---\n";
	try
	{
		// ✅ Creating a bureaucrat and a standard form
		Bureaucrat	boss("Alex", 10);
		Form		taxForm("Tax Return Form", 45, 30);

		std::cout << "1. " << boss << "\n\n";
		std::cout << "2. " << taxForm << "\n";

		// ✅ Bureaucrat signs the form successfully
		std::cout << "3. Attempting to sign the form...\n";
		boss.signForm(taxForm);

		// ✅ Showing the form state after signing
		std::cout << "4. Post-signing form state:\n   " << taxForm << "\n";

		// ❌ Bureaucrat can't sign the form the second time
		std::cout << "5. Attempting to sign the form...\n";
		boss.signForm(taxForm);
	}
	catch (std::exception& e)
	{
		std::cout << "XX. Exception caught: " << e.what() << "\n";
	}

	//////////////////////////////////////////////////////////////////////////////////////
	std::cout << "\n--- Test 2: Bureaucrat grade too low to sign ---\n";
	try
	{
		// ❌ Bureaucrat has grade 100, but form requires grade 50 to be signed
		Bureaucrat  lowGuy("Low Level Kevin", 100);
		Form        topSecretForm("Top Secret Document", 50, 20);

		std::cout << "1. " << lowGuy << "\n\n";
		std::cout << "2. " << topSecretForm << "\n";

		// ❌ This will internally catch the Form::GradeTooLowException via signForm
		std::cout << "3. Kevin tries to sign something above his paygrade...\n";
		lowGuy.signForm(topSecretForm);

		// ❌ This direct action will explicitly throw and jump to the catch block
		std::cout << "4. Forcing direct form.beSigned() call...\n\n";
		topSecretForm.beSigned(lowGuy);
		
		std::cout << "00. This line will never be reached\n";
	}
	catch (std::exception& e)
	{
		std::cout << "5. Exception caught: " << e.what() << "\n";
	}

	//////////////////////////////////////////////////////////////////////////////////////
	std::cout << "\n--- Test 3: Creating an invalid Form (Grade Too High) ---\n";
	try
	{
		// ❌ Trying to create a Form with an invalid sign grade (0)
		Form	illegalForm("Illegal Form", 0, 50);
		std::cout << "99. " << illegalForm << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << "1. Exception caught: " << e.what() << "\n";
	}

	return (0);
}

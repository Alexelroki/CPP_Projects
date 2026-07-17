#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::srand(std::time(NULL)); // Seed for random robotomy request form
	std::cout << "--- Test 1: Shrubbery Creation Form (Sign 145, Exec 137) ---\n";
	{
		Bureaucrat				lowOfficer("Low Intern", 140); // Can sign, cannot execute
		ShrubberyCreationForm	form("home");

		std::cout << form << "\n";
		lowOfficer.executeForm(form); // ❌ Error: Form is not signed yet
		
		lowOfficer.signForm(form);    // ✅ Successfully signs
		lowOfficer.executeForm(form); // ❌ Error: Grade 140 is insufficient to execute (137)

		Bureaucrat				highOfficer("Manager", 100); // Can do both
		highOfficer.executeForm(form);  // ✅ Success: Creates garden_shrubbery file
	}

	std::cout << "--- Test 2: Robotomy Request Form (Sign 72, Exec 45) ---\n";
	{
		Bureaucrat				staff("Staff Member", 60); // Can sign, cannot execute
		RobotomyRequestForm		form("Bender");

		staff.signForm(form);
		staff.executeForm(form); // ❌ Error: Grade 60 is insufficient to execute (45)

		Bureaucrat				boss("The Boss", 10);
		boss.executeForm(form);  // ✅ Success: Makes drilling noises and calculates 50% success rate
	}

	std::cout << "--- Test 3: Presidential Pardon Form (Sign 25, Exec 5) ---\n";
	{
		Bureaucrat				boss("The Boss", 10); // Can sign, cannot execute pardon
		PresidentialPardonForm	form("Criminal");

		boss.signForm(form);
		boss.executeForm(form); // ❌ Error: Grade 10 is insufficient to execute (5)

		Bureaucrat				president("Zaphod", 1);
		president.executeForm(form); // ✅ Absolute Success: Pardoned
	}

	return (0);
}
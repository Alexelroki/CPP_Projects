#include <iostream>
#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern( void ) {}

Intern::Intern( const Intern& other )
{
	(void)other;
}

Intern::~Intern( void ) {}

Intern&		Intern::operator=( const Intern& other )
{
	(void)other;
	return (*this);
}

static AForm*	createShrubbery( const std::string& target )
{
	return (new ShrubberyCreationForm(target));
}

static AForm*	createRobotomy( const std::string& target )
{
	return (new RobotomyRequestForm(target));
}

static AForm*	createPardon( const std::string& target )
{
	return (new PresidentialPardonForm(target));
}

AForm*			Intern::makeForm( const std::string& name, const std::string& target )
{
	static const std::string		formTypes[3] =
	{
		"shrubbery creation", "robotomy request", "presidential pardon"
	};

	static AForm* (*formCreators[3])(const std::string&) =
	{
		&createShrubbery, &createRobotomy, &createPardon
	};

	for (int i = 0; i < 3; i++)
	{
		if (formTypes[i] == name)
		{
			std::cout << "Intern creates " << name << "\n";
			return (formCreators[i](target));
		}
	}

	std::cout << "Error: Intern cannot create '" << name << "' because it is an unknown form type.\n";
	return (NULL);
}

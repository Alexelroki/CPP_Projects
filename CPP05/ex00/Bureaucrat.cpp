#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat::~Bureaucrat() {}

// Getters
std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int		Bureaucrat::getGrade() const
{
	return (this->_grade);
}

// Member Functions
void		Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void		Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

// Exceptions
const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat grade is too high! Maximum allowed is 1.");
}
const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat grade is too low! Minimum allowed is 150.");
}

// Stream Output Operator
std::ostream&	operator<<(std::ostream& o, const Bureaucrat& instance)
{
	o << instance.getName() << ", bureaucrat grade " << instance.getGrade() << ".";
	return (o);
}


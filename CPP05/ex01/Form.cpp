#include "Form.hpp"

Form::Form( void )
	: _name("DefaultForm"), _isSigned(0), _signGrade(150), _execGrade(150) {}

Form::Form( const std::string& name, int signGrade, int execGrade )
	: _name(name), _isSigned(0), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form( const Form& other )
	: _name(other._name), isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	if (other._signGrade < 1 || other._execGrade < 1)
		throw Form::GradeTooHighException();
	if (other._signGrade > 150 || other._execGrade > 150)
		throw Form::GradeTooLowException();
}

void	Form::beSigned( const Bureaucrat& signer )
{
	if ( signer._grade < this->_signGrade )
	{
		this->_isSigned = 1;
		std::cout << signer << " signed " << this->_name;
	}
	else
	{
		this->_isSigned = 1;
		std::cout << signer << " couldn't sign " << this->_name << " because the grade is not in the range (PUT SPECIFIC REASON HERE)";
	}
}


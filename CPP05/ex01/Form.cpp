#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form( void )
	: _name("DefaultForm"), _isSigned(false), _signGrade(150), _execGrade(150) {}

Form::Form( const std::string& name, int signGrade, int execGrade )
	: _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form( const Form& other )
	: _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	if (other._signGrade < 1 || other._execGrade < 1)
		throw Form::GradeTooHighException();
	if (other._signGrade > 150 || other._execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::~Form( void ) {}

void	Form::beSigned( const Bureaucrat& signer )
{
	if (this->_isSigned)
	{
		throw Form::AlreadySignedException();
	}
	if (signer.getGrade() > this->_signGrade)
	{
		throw Form::GradeTooLowException();
	}
	this->_isSigned = true;
}

// Getters
const std::string&	Form::getName( void ) const
{
	return (this->_name);
}

bool			Form::getIsSigned( void ) const
{
	return (this->_isSigned);
}

int			Form::getSignGrade( void ) const
{
	return (this->_signGrade);
}

int			Form::getExecGrade( void ) const
{
	return (this->_execGrade);
}

// Execeptions
const char*		Form::GradeTooHighException::what() const throw()
{
	return ("Form grade too high. The maximum grade is 1.");
}

const char*		Form::GradeTooLowException::what() const throw()
{
	return ("the bureaucrat's grade or the form's grade requirement is too low.\n");
}

const char*		Form::AlreadySignedException::what() const throw()
{
	return ("this form is already signed.");
}

std::ostream&	operator<<(std::ostream& o, const Form& instance)
{
	o
	<< "Form's name: " << instance.getName() << ".\n"
	<< "   Signed: " << (instance.getIsSigned() ? "Yes.\n" : "No.\n")
	<< "   Grade required to sign: " << instance.getSignGrade() << ".\n"
	<< "   Grade required to execute: " << instance.getExecGrade() << ".\n";
	return (o);
}

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm( void )
	: _name("DefaultForm"), _isSigned(false), _signGrade(150), _execGrade(150) {}

AForm::AForm( const std::string& name, int signGrade, int execGrade )
	: _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm( const AForm& other )
	: _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	if (other._signGrade < 1 || other._execGrade < 1)
		throw AForm::GradeTooHighException();
	if (other._signGrade > 150 || other._execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm( void ) {}

void	AForm::beSigned( const Bureaucrat& signer )
{
	if (this->_isSigned)
	{
		throw AForm::AlreadySignedException();
	}
	if (signer.getGrade() > this->_signGrade)
	{
		throw AForm::GradeTooLowException();
	}
	this->_isSigned = true;
}

void	AForm::execute( const Bureaucrat& executor ) const
{
	if (!this->_isSigned)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_execGrade)
		throw AForm::GradeTooLowException();
	this->executeAction();
}

// Getters
const std::string&	AForm::getName( void ) const
{
	return (this->_name);
}

bool			AForm::getIsSigned( void ) const
{
	return (this->_isSigned);
}

int			AForm::getSignGrade( void ) const
{
	return (this->_signGrade);
}

int			AForm::getExecGrade( void ) const
{
	return (this->_execGrade);
}

// Execeptions
const char*		AForm::GradeTooHighException::what() const throw()
{
	return ("AForm grade too high. The maximum grade is 1.");
}

const char*		AForm::GradeTooLowException::what() const throw()
{
	return ("the bureaucrat's grade is too low.\n");
}

const char*		AForm::AlreadySignedException::what() const throw()
{
	return ("this form is already signed.");
}

const char*		AForm::FormNotSignedException::what() const throw()
{
	return ("it is not signed.");
}

std::ostream&	operator<<(std::ostream& o, const AForm& instance)
{
	o
	<< "   Form's name: " << instance.getName() << ".\n"
	<< "   Signed: " << (instance.getIsSigned() ? "Yes.\n" : "No.\n")
	<< "   Grade required to sign: " << instance.getSignGrade() << ".\n"
	<< "   Grade required to execute: " << instance.getExecGrade() << ".\n";
	return (o);
}

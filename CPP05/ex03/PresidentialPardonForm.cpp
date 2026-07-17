#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( const std::string& target )
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other )
	: AForm(other), _target(other._target) {}

PresidentialPardonForm::~PresidentialPardonForm( void ) {}

void	PresidentialPardonForm::executeAction( void ) const
{
	std::cout << "   " << this->_target << " has been pardoned by Zaphod Beeblebrox.\n";
}

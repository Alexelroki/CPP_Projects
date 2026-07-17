#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( const std::string& target )
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other )
	: AForm(other), _target(other._target) {}

RobotomyRequestForm::~RobotomyRequestForm( void ) {}

void	RobotomyRequestForm::executeAction( void ) const
{
	std::cout << "   * BZZZZZ! DRILING NOISES * \n";

	if (std::rand() % 2 == 0)
		std::cout << "   " << this->_target << " has been robotomized succesfully (50\% of the time)!\n";
	else
		std::cout << "   The robotomy on " << this->_target << " failed.\n";
}

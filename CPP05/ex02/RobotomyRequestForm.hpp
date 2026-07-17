#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm( const std::string& target );
		RobotomyRequestForm( const RobotomyRequestForm& other );
		virtual ~RobotomyRequestForm( void );

	protected:
		virtual void	executeAction( void ) const;

	private:
		const std::string	_target;
		RobotomyRequestForm( void );
		RobotomyRequestForm&	operator=( const RobotomyRequestForm& other );
};

#endif
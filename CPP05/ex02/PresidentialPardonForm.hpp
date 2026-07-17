#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm( const std::string& target );
		PresidentialPardonForm( const PresidentialPardonForm& other );
		virtual ~PresidentialPardonForm( void );

	protected:
		virtual void	executeAction( void ) const;

	private:
		const std::string	_target;
		PresidentialPardonForm( void );
		PresidentialPardonForm&	operator=( const PresidentialPardonForm& other );
};

#endif
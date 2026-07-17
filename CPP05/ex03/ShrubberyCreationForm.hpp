#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm( const std::string& target );
		ShrubberyCreationForm( const ShrubberyCreationForm& other );
		virtual ~ShrubberyCreationForm( void );

	protected:
		virtual void	executeAction( void ) const;

	private:
		const std::string	_target;
		ShrubberyCreationForm( void );
		ShrubberyCreationForm&	operator=( const ShrubberyCreationForm& other );
};

#endif
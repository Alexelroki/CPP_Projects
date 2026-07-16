#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class Form
{
	public:
		// Orthodox Canonical Form
		Form( void );
		Form( const std::string& name, int signGrade, int execGrade );
		Form( const Form& other );
		~Form( void );

		// Functions
		void		beSigned( const Bureaucrat& signer );

		// Getters
		const std::string&	getName( void ) const;
		bool				getIsSigned( void ) const;
		int					getSignGrade( void ) const;
		int					getExecGrade( void ) const;

		// Nested custom exception classes
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;

		// Disabled assignment operator due to const attribute design constraints
		Form&				operator=( const Form& src );
};

std::ostream&				operator<<(std::ostream& o, const Form& instance);

#endif

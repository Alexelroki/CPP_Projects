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

		// Getters
		const std::string&	getName( void ) const;
		bool			getIsSigned( void ) const;
		int			getSignGrade( void ) const;
		int			getExecGrade( void ) const;

		// Functions
		void		beSigned( const Bureaucrat& signer );

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
		bool			_isSigned;
		const int		_signGrade;
		const int		_execGrade;
};

std::ostream&	operator<<(std::ostream& o, const Form& instance);

#endif

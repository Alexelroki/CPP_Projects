#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class AForm
{
	public:
		// Orthodox Canonical Form
		AForm( void );
		AForm( const std::string& name, int signGrade, int execGrade );
		AForm( const AForm& other );
		virtual ~AForm( void );

		// Functions
		void		beSigned( const Bureaucrat& signer );
		void		execute( const Bureaucrat& executor ) const;

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
		class AlreadySignedException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

	protected:
		virtual void		executeAction( void ) const = 0;

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;

		// Disabled assignment operator due to const attribute design constraints
		AForm&				operator=( const AForm& src );
};

std::ostream&				operator<<(std::ostream& o, const AForm& instance);

#endif

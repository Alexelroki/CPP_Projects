#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
	public:
		// Orthodox Canonical Form
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();

		// Getters
		std::string	getName() const;
		int		getGrade() const;

		// Member Functions
		void		incrementGrade();
		void		decrementGrade();

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
		int			_grade;

		// Disabled assignment operator due to const attribute design constraints
		Bureaucrat&		operator=(const Bureaucrat& src);
};

//void            signForm( const Bureaucrat& signer );

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& instance);

#endif

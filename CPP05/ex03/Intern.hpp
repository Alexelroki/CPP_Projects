#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>

class AForm;

class Intern
{
	public:
		// Orthodox Canonical Form
		Intern( void );
		Intern( const Intern& other );
		Intern&		operator=( const Intern& other );
		~Intern( void );

		// The intern class has one key ability: the makeForm()
		AForm*		makeForm(const std::string& name, const std::string& target);
};

#endif
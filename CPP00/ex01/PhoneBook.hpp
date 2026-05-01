#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip> // Para std::setw (formato de tabla)

class Phonebook
{
	private:
		Contact	_contacts[8];
		int		_total;
		int		_next;

	public:
		Phonebook();
		~Phonebook();

		void	setContact();
		void	getContactInfo();
		void	getContactList();
}

#endif

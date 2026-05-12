#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>
# include <iostream>
# include <cstdlib>

void	bye(void);

class PhoneBook
{
	private:
		Contact	_contacts[8];
		int		_total;
		int		_next;

	public:
		PhoneBook();
		~PhoneBook();

		bool	setContact(void);
		int		getContactList(void) const;
		void	getContactInfo(const std::string& input) const;
};

#endif

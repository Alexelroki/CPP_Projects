#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>
# include <iostream>
# include <cstdlib>

class PhoneBook
{
	private:
		Contact	_contacts[8];
		int		_total;
		int		_next;

	public:
		PhoneBook();
		~PhoneBook();

		void	setContact(void);
		int		getContactList(void) const;
		void	getContactInfo(const std::string& input) const;
};

#endif

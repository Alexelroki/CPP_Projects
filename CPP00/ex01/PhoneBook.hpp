#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>
# include <iostream>

class PhoneBook
{
	private:
		Contact	_contacts[8];
		int		_total;
		int		_next;

	public:
		PhoneBook();
		~PhoneBook();

		void	setContact();
		void	getContactList() const;
		Contact	getContactInfo(int who) const;
};

#endif

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>

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
		bool	getContactList(void) const;
		bool	getContactInfo(const std::string& input) const;
};

#endif

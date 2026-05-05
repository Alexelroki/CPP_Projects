#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): _total(0), _next(0) {}
PhoneBook::~PhoneBook() {}

static void	_getInput(std::string prompt, std::string& field)
{
	while (field.empty())
	{
		std::cout << prompt;
		if (!std::getline(std::cin, field))
			return ;
		if (field.empty())
			std::cout << "Input cannot be empty. Please try again." << std::endl;
	}
}

void	PhoneBook::setContact()
{
	std::string first, last, nick, phone, darkest;

	_getInput("First name: ", first);
	_getInput("Last name: ", last);
	_getInput("Nick name: ", nick);
	_getInput("Phone number: ", phone);
	_getInput("Darkest secret: ", darkest);

	if (first.empty() || last.empty() || nick.empty() || phone.empty() || darkest.empty())
		return ;

	_contacts[_next].setFirstName(first);
	_contacts[_next].setLastName(last);
	_contacts[_next].setNickName(nick);
	_contacts[_next].setPhoneNumber(phone);
	_contacts[_next].setDarkestSecret(darkest);

	_next = (_next + 1) % 8;
	if (_total < 8)
		_total += 1;
}

static std::string	formatString(const std::string& str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	PhoneBook::getContactList() const
{
	std::cout << "|" << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "FirstName";
	std::cout << "|" << std::setw(10) << "LastName";
	std::cout << "|" << std::setw(10) << "Nickname" << "|" << std::endl;

	for (int i = 0; i < _total; i++)
	{
		std::cout << "|" << std::setw(10) << i;
		std::cout << "|" << std::setw(10) << formatString(_contacts[i].getFirstName());
		std::cout << "|" << std::setw(10) << formatString(_contacts[i].getLastName());
		std::cout << "|" << std::setw(10) << formatString(_contacts[i].getNickName());
		std::cout << "|" << std::endl;
	}
}

Contact	PhoneBook::getContactInfo(int who) const
{
	if (who < 0 || who >= _total)
		return Contact();
	return (_contacts[who]);
}

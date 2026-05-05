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
		std::cout << "|" << std::setw(10) << i + 1;
		std::cout << "|" << std::setw(10) << formatString(_contacts[i].getFirstName());
		std::cout << "|" << std::setw(10) << formatString(_contacts[i].getLastName());
		std::cout << "|" << std::setw(10) << formatString(_contacts[i].getNickName());
		std::cout << "|" << std::endl;
	}
}

void	PhoneBook::getContactInfo(const std::string& input) const
{
	if (input.length() != 1 || input[0] < '1' || input[0] > '8')
	{
		std::cout << "Invalid index or no contacts" << std::endl;
		return ;
	}

	int	who = input[0] - '1';

	if (who >= _total)
	{
		std::cout << "Error: Contact #" << who << " does not exist yet." << std::endl;
		return ;
	}
	std::cout << "First name: " << _contacts[who].getFirstName() << std::endl;
	std::cout << "Last name: " << _contacts[who].getLastName() << std::endl;
	std::cout << "Nick name: " << _contacts[who].getNickName() << std::endl;
	std::cout << "Phone number: " << _contacts[who].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << _contacts[who].getDarkestSecret() << std::endl;
}

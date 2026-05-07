#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): _total(0), _next(0) {}
PhoneBook::~PhoneBook() {}

static void	_getInput(std::string prompt, std::string& field)
{
	while (field.empty())
	{
		std::cout << prompt << std::flush;
		if (!std::getline(std::cin, field))
		{
			std::cout << "\n" << RED << "Input cancelled." << RESET << std::endl;
			std::cout << "\n" << YELLOW << "Goodbye!" << RESET << std::endl;
			exit(0);
		}
		if (field.empty())
			std::cout << RED << "Input cannot be empty. Please try again." << RESET << std::endl;
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

int	PhoneBook::getContactList() const
{
	if (_total < 1)
	{
		std::cout << RED << "No contacts available" << RESET << std::endl;
		std::cout << RED << "Use the \"ADD\" command to create contacts" << RESET << std::endl;
		return (0);
	}

	std::cout << GREEN << "---------------------------------------------" << RESET << std::endl;
	std::cout << GREEN << "|" << std::setw(10) << "Index" << RESET;
	std::cout << GREEN << "|" << std::setw(10) << "FirstName" << RESET;
	std::cout << GREEN << "|" << std::setw(10) << "LastName" << RESET;
	std::cout << GREEN << "|" << std::setw(10) << "Nickname" << "|" << RESET << std::endl;
	std::cout << GREEN << "---------------------------------------------" << RESET << std::endl;

	for (int i = 0; i < _total; i++)
	{
		std::cout << GREEN << "|" << BLUE << std::setw(10) << i + 1 << RESET;
		std::cout << GREEN << "|" << BLUE << std::setw(10) << formatString(_contacts[i].getFirstName()) << RESET;
		std::cout << GREEN << "|" << BLUE << std::setw(10) << formatString(_contacts[i].getLastName()) << RESET;
		std::cout << GREEN << "|" << BLUE << std::setw(10) << formatString(_contacts[i].getNickName()) << RESET;
		std::cout << GREEN << "|" << RESET << std::endl;
		std::cout << GREEN << "---------------------------------------------" << RESET << std::endl;
	}
	return (1);
}

void	PhoneBook::getContactInfo(const std::string& input) const
{
	if (input.length() != 1 || input[0] < '1' || input[0] > '8')
	{
		std::cout << RED << "Invalid index" << RESET << std::endl;
		return ;
	}

	int	who = input[0] - '1';

	if (who >= _total)
	{
		std::cout << RED << "Error: Contact #" << who << " does not exist yet." << RESET << std::endl;
		return ;
	}
	std::cout << BLUE << "First name: " << _contacts[who].getFirstName() << RESET << std::endl;
	std::cout << BLUE << "Last name: " << _contacts[who].getLastName() << RESET << std::endl;
	std::cout << BLUE << "Nick name: " << _contacts[who].getNickName() << RESET << std::endl;
	std::cout << BLUE << "Phone number: " << _contacts[who].getPhoneNumber() << RESET << std::endl;
	std::cout << BLUE << "Darkest secret: " << _contacts[who].getDarkestSecret() << RESET << std::endl;
}

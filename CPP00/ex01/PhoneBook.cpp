#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): _total(0), _next(0) {}
PhoneBook::~PhoneBook() {}

void	PhoneBook::setContact()
{
	std::string first, last, nick, phone, darkest;

	// Dividir esta función en dos, para comprobar que no haya ningún
	// campo de la tabla vacío, con algo como:
	/*void    PhoneBook::setContact()
	{
		std::string first;

		// Usamos un bucle para obligar a que escriba algo
		while (first.empty()) 
		{
			std::cout << "First name: ";
			if (!std::getline(std::cin, first)) // Protección extra por si pulsan Ctrl+D
				return ;
			if (first.empty())
				std::cout << "Error: Field can't be empty." << std::endl;
		}
		
		// Una vez que sale del while, ya tienes un 'first' con contenido
		_contacts[_next].setFirstName(first);
		
		// ... repetir lo mismo para los demás campos ...
	}*/

	std::cout << "First name: " << std::endl;
	std::getline(std::cin, first);
	std::cout << "Last name: " << std::endl;
	std::getline(std::cin, last);
	std::cout << "Nick name: " << std::endl;
	std::getline(std::cin, nick);
	std::cout << "Phone number: " << std::endl;
	std::getline(std::cin, phone);
	std::cout << "Darkest secret: " << std::endl;
	std::getline(std::cin, darkest);

	_contacts[_next].setFirstName(first);
	_contacts[_next].setLastName(last);
	_contacts[_next].setNickName(nick);
	_contacts[_next].setPhoneNumber(phone);
	_contacts[_next].setDarkestSecret(darkest);

	_next = (_next + 1) % 8;
	if (_total < 8)
		_total += 1;
}

static std::string	formatString(std::string str)
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
	return (_contacts[who]);
}

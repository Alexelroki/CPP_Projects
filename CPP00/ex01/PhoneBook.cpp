#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): _total(0), _next(0) {}
PhoneBook::~PhoneBook() {}

void	bye()
{
	std::cout << "\n" << RED << "Input cancelled." << RESET;
	std::cout << "\n" << YELLOW << "Goodbye!" << RESET << std::endl;
}

static bool	_isValidPhone(const std::string& phone)
{
	if (phone.length() < 7 || phone.length() > 15)
		return (false);
	if (phone.find_first_not_of("0123456789") != std::string::npos)
		return (false);
	return (true);
}

static bool	_getInput(std::string prompt, std::string& field)
{
	while (true)
	{
		if (std::cin.eof())
		{
			bye();
			return (false);
		}
		std::cout << prompt << std::flush;
		if (!std::getline(std::cin, field))
		{
			bye();
			return (false);
		}
		if (!field.empty())
			break ;
		std::cout << RED << "Input cannot be empty. Please try again." << RESET << std::endl;
	}
	return (true);
}

static int	getCharInfo(const std::string& str, size_t i, size_t& bytes)
{
	unsigned char	c = str[i];
	int				cp;

	// Miramos el primer bit, si es 0, es una letra inglesa normal, ocupa 1 espacio
	// 0x80 = 1000 0000
	if ((c & 0x80) == 0)
	{
		bytes = 1;
		return (1);
	}
	// Miramos los tres primeros bits, si es 110, ocupa 2 bytes pero solo 1 espacio (p.ej. ñ, á, ...)
	// 0xE0 = 1110 0000
	// 0xC0 = 1100 0000
	if ((c & 0xE0) == 0xC0)
	{
		bytes = 2;
		return (1);
	}
	// Miramos los cuatro primeros bits, si es 1110, ocupa 2 bytes, pero puede ocupar 1 o 2 espacios
	// 0xF0 = 1111 0000
	// 0xE0 = 1110 0000
	if ((c & 0xF0) == 0xE0)
	{
		// Tenemos que fusionar los 3 bytes para ver el número real de la letra (Code Point).
		bytes = 3;
		if (i + 2 < str.length()) // Comprobación de seguridad (¿Existen los siguientes dos bytes?)
		{
			// Extraemos los bits que no son de control
			// 0x0F = 0000 1111 - Conserva 4 ultimos bits del primer byte
			// 0x3F = 0011 1111 - Conserva 6 ultimos bits del segundo y tercer byte
			// 4 + 6 + 6 = 16 bits
			// Coges los 4 primeros, los mueves 12 posiciones a la izquierda, ahora te quedan
			// 12 posiciones libres a la derecha, metes 6 y 6 de los otros dos bytes
			// Estamos leyendo UTF-8, pero calculando su valor Unicode real (Code Point) en la RAM.
			cp = ((c & 0x0F) << 12) | ((str[i + 1] & 0x3F) << 6) | (str[i + 2] & 0x3F);
			if ((cp >= 0x1100 && cp <= 0x11FF) || (cp >= 0x2E80 && cp <= 0xA4CF) ||
				(cp >= 0xAC00 && cp <= 0xD7AF) || (cp >= 0xF900 && cp <= 0xFAFF))
				return (2);
		}
		return (1);
	}
	// Miramos los cinco primeros bits, si es 1111 0, ocupa 4 bytes, pero puede ocupar 1 o 2 espacios
	// 0xF0 = 1111 0000
	// 0xE0 = 1110 0000
	if ((c & 0xF8) == 0xF0)
	{
		bytes = 4;
		return (2);
	}
	// Por robustez frente a textos corruptos o bytes extraños, se lo salta y lo ignora.
	bytes = 1;
	return (0);
}

static size_t	countVisualChars(const std::string& str)
{
	size_t	total = 0;
	size_t	i = 0;

	while (i < str.length())
	{
		size_t	bytes;
		total += getCharInfo(str, i, bytes);
		i += bytes;
	}
	return (total);
}

static bool	_check(int i, const std::string& info)
{
	if (i < 3 && countVisualChars(info) > 15)
	{
		std::cout << RED << "Input fields have maximum length limits: " << RESET << std::endl;
		std::cout << RED << "First name, Last name, Nick name: 15 characters." << RESET << std::endl;
		return (false);
	}
	else if (i == 3 && !_isValidPhone(info))
	{
		if (std::cin.eof())
			return (false);
		std::cout << RED << "Invalid phone number. Try again.\nPhone number must have more than 7 and less than 15 digits." << RESET << std::endl;
		return (false);
	}
	else if (i == 4 && countVisualChars(info) > 255)
	{
		std::cout << RED << "Darkest secret: 255 characters." << RESET << std::endl;
		return (false);
	}
	return (true);
}

bool	PhoneBook::setContact()
{
	std::string	info[5];
	const char*	prompts[5] = {"First name: ", "Last name: ", "Nick name: ", "Phone number: ", "Darkest secret: "};

	for (int i = 0; i < 5; i++)
	{
		if (!_getInput(prompts[i], info[i]))
			return (false);
		if (!_check(i, info[i]))
			i--;
	}

	_contacts[_next].setFirstName(info[0]);
	_contacts[_next].setLastName(info[1]);
	_contacts[_next].setNickName(info[2]);
	_contacts[_next].setPhoneNumber(info[3]);
	_contacts[_next].setDarkestSecret(info[4]);

	_next = (_next + 1) % 8;
	if (_total < 8)
		_total += 1;
	return (true);
}

static std::string	formatString(const std::string& str)
{
	size_t	i = 0;
	size_t	width = 0;
	size_t	cut = 0;
	size_t	totalW = countVisualChars(str);

	if (totalW <= 10)
		return (std::string(10 - totalW, ' ') + str);

	while (i < str.length())
	{
		size_t	bytes;
		size_t	w = getCharInfo(str, i, bytes);
		if (width + w > 9)
			break ;
		width += w;
		cut = i;
		i += bytes;
	}

	std::string	res = str.substr(0, cut) + ".";
	return (std::string(10 - countVisualChars(res), ' ') + res);
}

bool	PhoneBook::getContactList() const
{
	if (_total < 1)
	{
		std::cout << RED << "No contacts available." << RESET << std::endl;
		std::cout << RED << "Use the \"ADD\" command to create contacts." << RESET << std::endl;
		return (false);
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
		std::cout << GREEN << "|" << BLUE << formatString(_contacts[i].getFirstName()) << RESET;
		std::cout << GREEN << "|" << BLUE << formatString(_contacts[i].getLastName()) << RESET;
		std::cout << GREEN << "|" << BLUE << formatString(_contacts[i].getNickName()) << RESET;
		std::cout << GREEN << "|" << RESET << std::endl;
		std::cout << GREEN << "---------------------------------------------" << RESET << std::endl;
	}
	return (true);
}

bool	PhoneBook::getContactInfo(const std::string& input) const
{
	if (input.length() != 1 || input[0] < '1' || input[0] > '8')
	{
		std::cout << RED << "Invalid index." << RESET << std::endl;
		return (false);
	}

	int	who = input[0] - '1';

	if (who >= _total)
	{
		std::cout << RED << "Error: Contact #" << input[0] << " does not exist yet." << RESET << std::endl;
		return (false);
	}
	std::cout << BLUE << "First name: " << _contacts[who].getFirstName() << RESET << std::endl;
	std::cout << BLUE << "Last name: " << _contacts[who].getLastName() << RESET << std::endl;
	std::cout << BLUE << "Nick name: " << _contacts[who].getNickName() << RESET << std::endl;
	std::cout << BLUE << "Phone number: " << _contacts[who].getPhoneNumber() << RESET << std::endl;
	std::cout << BLUE << "Darkest secret: " << _contacts[who].getDarkestSecret() << RESET << std::endl;
	return (true);
}

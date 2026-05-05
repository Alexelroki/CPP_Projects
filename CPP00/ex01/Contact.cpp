#include "Contact.hpp"

Contact::Contact(): _firstName(""), _lastName(""), _nickName(""), _phoneNumber(""), _darkestSecret("") {}
Contact::~Contact() {}

void	Contact::setFirstName(const std::string& f)
{
	_firstName = f;
}

void	Contact::setLastName(const std::string& l)
{
	_lastName = l;
}

void	Contact::setNickName(const std::string& n)
{
	_nickName = n;
}

void	Contact::setPhoneNumber(const std::string& p)
{
	_phoneNumber = p;
}

void	Contact::setDarkestSecret(const std::string& d)
{
	_darkestSecret = d;
}

std::string	Contact::getFirstName() const
{
	return (_firstName);
}

std::string	Contact::getLastName() const
{
	return (_lastName);
}

std::string	Contact::getNickName() const
{
	return (_nickName);
}

std::string	Contact::getPhoneNumber() const
{
	return (_phoneNumber);
}

std::string	Contact::getDarkestSecret() const
{
	return (_darkestSecret);
}

#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

void Contact::init(std::string f, std::string l, std::string n, std::string p, std::string s) {
    this->_firstName = f;
    this->_lastName = l;
    this->_nickname = n;
    this->_phoneNumber = p;
    this->_darkestSecret = s;
}

std::string Contact::getFirstName() const { return _firstName; }
std::string Contact::getLastName() const { return _lastName; }
std::string Contact::getNickname() const { return _nickname; }
std::string Contact::getPhoneNumber() const { return _phoneNumber; }
std::string Contact::getDarkestSecret() const { return _darkestSecret; }

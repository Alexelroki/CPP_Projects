#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _count(0), _index(0) {}
PhoneBook::~PhoneBook() {}

void PhoneBook::add() {
    std::string f, l, n, p, s;
    std::cout << "First Name: "; std::getline(std::cin, f);
    std::cout << "Last Name: "; std::getline(std::cin, l);
    std::cout << "Nickname: "; std::getline(std::cin, n);
    std::cout << "Phone: "; std::getline(std::cin, p);
    std::cout << "Secret: "; std::getline(std::cin, s);

    if (f.empty() || l.empty() || n.empty() || p.empty() || s.empty()) {
        std::cout << "Error: Empty fields not allowed." << std::endl;
        return;
    }
    _contacts[_index].init(f, l, n, p, s);
    _index = (_index + 1) % 8; // Buffer circular [cite: 149]
    if (_count < 8) _count++;
}

std::string truncate(std::string str) {
    if (str.length() > 10)
        return str.substr(0, 9) + "."; // Reemplaza el décimo por un punto [cite: 171]
    return str;
}

void PhoneBook::search() const {
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    for (int i = 0; i < _count; i++) {
        std::cout << "|" << std::setw(10) << i;
        std::cout << "|" << std::setw(10) << truncate(_contacts[i].getFirstName());
        std::cout << "|" << std::setw(10) << truncate(_contacts[i].getLastName());
        std::cout << "|" << std::setw(10) << truncate(_contacts[i].getNickname()) << "|" << std::endl;
    }
}

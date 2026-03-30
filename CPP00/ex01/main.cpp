#include "PhoneBook.hpp"

int main() {
    PhoneBook pb;
    std::string cmd;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, cmd) || cmd == "EXIT") break;
        if (cmd == "ADD") pb.add();
        else if (cmd == "SEARCH") pb.search();
    }
    return 0;
}

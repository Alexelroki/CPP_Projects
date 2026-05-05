#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	pb;
	std::string	command;

	while (1)
	{
		std::cout << "Enter command (ADD, SEARCH or EXIT): ";
		if (!std::getline(std::cin, command))
			break ;
		if (command == "ADD")
			pb.setContact();
		else if (command == "SEARCH")
		{
			pb.getContactList();
			std::string	index_str;
			std::cout << "Enter index: ";
			if (std::getline(std::cin, index_str))
				pb.getContactInfo(index_str);
		}
		else if (command == "EXIT")
			break ;
	}
	return (0);
}

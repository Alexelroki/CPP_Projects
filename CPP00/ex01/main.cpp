#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	pb;
	std::string	command;

	while (1)
	{
		std::cout << YELLOW << "Enter command (ADD, SEARCH or EXIT): " << RESET;
		if (!std::getline(std::cin, command))
		{
			std::cout << "\n" << YELLOW << "Goodbye!" << RESET << std::endl;
			break ;
		}
		if (command == "ADD")
			pb.setContact();
		else if (command == "SEARCH" && pb.getContactList())
		{
			std::string	index_str;
			std::cout << YELLOW << "Enter index: " << RESET;
			if (!std::getline(std::cin, index_str))
			{
				std::cout << "\n" << YELLOW << "Goodbye!" << RESET << std::endl;
				break ;
			}
			pb.getContactInfo(index_str);
		}
		else if (command == "EXIT")
			break ;
		else
		{
			std::cout << RED << "Invalid command" << RESET << std::endl;
			std::cout << "\n" << YELLOW << "Goodbye!" << RESET << std::endl;
		}
	}
	return (0);
}

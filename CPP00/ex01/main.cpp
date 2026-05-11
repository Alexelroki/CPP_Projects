#include "PhoneBook.hpp"

int	main(int argc, char **argv)
{
	PhoneBook	pb;
	std::string	command;

	(void)argv;
	if (argc > 1)
	{
		std::cout << RED << "Usage: \"./PhoneBook\", with no more arguments." << RESET << std::endl;
		return (1);
	}
	while (1)
	{
		std::cout << YELLOW << "Enter command (ADD, SEARCH or EXIT): " << RESET;
		if (!std::getline(std::cin, command) || std::cin.eof())
		{
			std::cout << "\n" << YELLOW << "Goodbye!" << RESET << std::endl;
			break ;
		}
		if (command == "ADD" && !pb.setContact())
			break ;
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
			std::cout << RED << "Invalid command" << RESET << std::endl;
	}
	return (0);
}

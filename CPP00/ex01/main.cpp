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
			bye();
			break ;
		}
		if (command == "ADD")
		{
			if (!pb.setContact())
				break;
		}
		else if (command == "SEARCH" && pb.getContactList())
		{
			std::string	index_str;
			std::cout << YELLOW << "Enter index: " << RESET;
			if (!std::getline(std::cin, index_str) || std::cin.eof())
			{
				bye();
				break ;
			}
			pb.getContactInfo(index_str);
		}
		else if (command == "EXIT")
			break ;
		else
			std::cout << RED << "Invalid command." << RESET << std::endl;
	}
	return (0);
}

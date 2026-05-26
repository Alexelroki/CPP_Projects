#include "PhoneBook.hpp"
#include <iostream>

#define RESET		"\033[0m"
#define RED			"\033[31m"
#define YELLOW		"\033[33m"

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
				break ;
		}
		else if (command == "SEARCH")
		{
			if (pb.getContactList())
			{
				while (true)
				{
					std::string	index_str;
					std::cout << YELLOW << "Enter index: " << RESET;
					if (!std::getline(std::cin, index_str) || std::cin.eof())
					{
						bye();
						return (0);
					}
					if (pb.getContactInfo(index_str))
						break ;
				}
			}
		}
		else if (command == "EXIT")
		{
			std::cout << YELLOW << "Goodbye!" << RESET << std::endl;
			break ;
		}
		else
			std::cout << RED << "Invalid command." << RESET << std::endl;
	}
	return (0);
}

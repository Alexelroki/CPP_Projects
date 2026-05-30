#include "Harl.hpp"
#include <iostream>

Harl::Harl( void ) {}
Harl::~Harl( void ) {}

void	Harl::_debug( void ) const
{
	std::cout << "[ DEBUG ]\nI love having extra bacon for my burger. I really do!" << std::endl;
}

void	Harl::_info( void ) const
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money." << std::endl;
}

void	Harl::_warning( void ) const
{
	std::cout << "[ WARNING ]\nI think I deserve some free extra bacon." << std::endl;
}

void	Harl::_error( void ) const
{
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.";
}

void	Harl::complain( const std::string& level ) const
{
	std::string	levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR", };

	void	(Harl::*methods[4])( void ) const =
	{
		&Harl::_debug,
		&Harl::_info,
		&Harl::_warning,
		&Harl::_error
	};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*methods[i])();
			return ;
		}
	}
}

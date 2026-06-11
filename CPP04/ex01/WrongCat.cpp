#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat( void ) : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat( const WrongCat& other ) : WrongAnimal(other)
{
	this->type = other.type;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat&	WrongCat::operator=( const WrongCat& other )
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
		this->type = other.type;
	}
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	return (*this);
}

WrongCat::~WrongCat( void )
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "Purr... Purr.." << std::endl;
}

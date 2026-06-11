#include "Animal.hpp"
#include <iostream>

Animal::Animal( void ) : type("Default")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal( const Animal& other ) : type(other.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal&	Animal::operator=( const Animal& other )
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << "Animal copy assignment operator called" << std::endl;
	return (*this);
}

Animal::~Animal( void )
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string	Animal::getType( void ) const
{
	return (this->type);
}

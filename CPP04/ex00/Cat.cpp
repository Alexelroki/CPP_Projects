#include "Cat.hpp"
#include <iostream>

Cat::Cat( void ) : Animal()
{
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat( const Cat& other ) : Animal(other)
{
	this->type = other.type;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat&	Cat::operator=( const Cat& other )
{
	if (this != &other)
	{
		Animal::operator=(other);
		this->type = other.type;
	}
	std::cout << "Cat copy assignment operator called" << std::endl;
	return (*this);
}

Cat::~Cat( void )
{
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound( void ) const
{
	std::cout << "Meow, meow!" << std::endl;
}

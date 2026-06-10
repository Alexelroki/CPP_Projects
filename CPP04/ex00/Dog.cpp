#include "Dog.hpp"
#include <iostream>

Dog::Dog( void ) : Animal()
{
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog( const Dog& other ) : Animal(other)
{
	this->type = other.type;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog&	Dog::operator=( const Dog& other )
{
	if (this != &other)
	{
		Animal::operator=(other);
		this->type = other.type;
	}
	std::cout << "Dog copy assignment operator called" << std::endl;
	return (*this);
}

Dog::~Dog( void )
{
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound( void ) const
{
	std::cout << "Woof, woof!" << std::endl;
}

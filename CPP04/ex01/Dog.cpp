#include "Dog.hpp"
#include <iostream>

Dog::Dog( void ) : Animal(), _brain(new Brain())
{
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog( const Dog& other ) : Animal(other), _brain(new Brain(*other._brain))
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
		*this->_brain = *other._brain;
	}
	std::cout << "Dog copy assignment operator called" << std::endl;
	return (*this);
}

Dog::~Dog( void )
{
	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound( void ) const
{
	std::cout << "Woof, woof!" << std::endl;
}

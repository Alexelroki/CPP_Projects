#include "Cat.hpp"
#include <iostream>

Cat::Cat( void ) : Animal(), _brain(new Brain())
{
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat( const Cat& other ) : Animal(other), _brain(new Brain(*other._brain))
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
		*this->_brain = *other._brain;
	}
	std::cout << "Cat copy assignment operator called" << std::endl;
	return (*this);
}

Cat::~Cat( void )
{
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound( void ) const
{
	std::cout << "Meow, meow!" << std::endl;
}

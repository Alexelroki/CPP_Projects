#include "FragTrap.hpp"
#include <iostream>

// Default constructor
FragTrap::FragTrap( void ) : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

// Name constructor
FragTrap::FragTrap( const std::string& name ) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap name constructor called" << std::endl;
}

// Copy constructor
FragTrap::FragTrap( const FragTrap& other ) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

// Assignment operator
FragTrap& FragTrap::operator=( const FragTrap& other )
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return *this;
}

// Destructor
FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap destructor called" << std::endl;
}

// Special ability
void FragTrap::highFivesGuys( void )
{
	if (this->_hitPoints == 0 || this->_energyPoints == 0)
	{
		std::cout
		<< "FragTrap " << this->_name
		<< " cannot request anything because it has no HP or energy left!"
		<< std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << " requests a positive high five! 🖐️" << std::endl;
}

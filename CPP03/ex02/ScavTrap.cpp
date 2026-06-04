#include "ScavTrap.hpp"
#include <iostream>

// Default constructor
ScavTrap::ScavTrap( void ) : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

// Name constructor
ScavTrap::ScavTrap( const std::string& name ) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap name constructor called" << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap( const ScavTrap& other ) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

// Assignment operator
ScavTrap& ScavTrap::operator=( const ScavTrap& other )
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return *this;
}

// Destructor
ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

// Overridden attack function with a specific ScavTrap message
void ScavTrap::attack( const std::string& target )
{
	if (this->_hitPoints == 0 || this->_energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " cannot attack because it has no HP or energy left!" << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << "ScavTrap " << this->_name << " fiercely attacks " << target 
			  << ", dealing " << this->_attackDamage << " points of damage!" << std::endl;
}

// Unique capability
void ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}
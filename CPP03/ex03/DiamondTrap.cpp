#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap( void )
	: ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(), _name("Default")
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( const std::string& name )
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) 
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	std::cout << "DiamondTrap name constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap& other )
	: ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=( const DiamondTrap& other )
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_name = other._name;
	}
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

// We need to choose the ScavTrap implementation
void	DiamondTrap::attack( const std::string& target )
{
	ScavTrap::attack(target);
}

// DiamondTrap special capability
void	DiamondTrap::whoAmI( void )
{
	if (this->_hitPoints == 0 || this->_energyPoints == 0)
	{
		std::cout
		<< "DiamondTrap " << this->_name
		<< " cannot state its identity because it has no HP or energy left!"
		<< std::endl;
		return ;
	}
	std::cout << "My DiamondTrap name is: " << this->_name << std::endl;
	std::cout << "My ClapTrap name is: " << ClapTrap::_name << std::endl;
}

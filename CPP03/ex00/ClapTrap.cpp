#include "ClapTrap.hpp"
#include <iostream>

// Orthodox Canonical Form
ClapTrap::ClapTrap( void )
	:	_name("Default"),
		_hitPoints(10),
		_energyPoints(10),
		_attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap( const std::string& name )
	:	_name(name),
		_hitPoints(10),
		_energyPoints(10),
		_attackDamage(0)
{
	std::cout << "Named constructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& other )
	:	_name(other._name),
		_hitPoints(other._hitPoints),
		_energyPoints(other._energyPoints),
		_attackDamage(other._attackDamage)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& other )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "Destructor called" << std::endl;
}

void	ClapTrap::attack( const std::string& target )
{
	if (this->_hitPoints == 0 || this->_energyPoints == 0)
	{
		std::cout
		<< "ClapTrap " << this->_name
		<< " cannot attack because it has no hit points or energy points left!"
		<< std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout
	<< "ClapTrap " << this->_name
	<< " attacks " << target
	<< ", causing " << this->_attackDamage
	<< " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (this->_hitPoints == 0)
	{
		std::cout
		<< "ClapTrap " << this->_name
		<< " is already dead!"
		<< std::endl;
		return;
	}
	if (amount >= this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout
	<< "ClapTrap " << this->_name
	<< " took " << amount
	<< " points of damage! Current HP: " << this->_hitPoints
	<< std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (this->_hitPoints == 0 || this->_energyPoints == 0)
	{
		std::cout
		<< "ClapTrap " << this->_name
		<< " cannot repair itself because it has no hit points or energy points left!"
		<< std::endl;
		return;
	}
	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout
	<< "ClapTrap " << this->_name
	<< " repairs itself, regaining "
	<< amount << " hit points! Current HP: " << this->_hitPoints
	<< std::endl;
}

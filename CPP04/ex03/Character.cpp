#include "Character.hpp"
#include <iostream>

Character::Character( const std::string& name ) : _name(name)
{
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
	}
}

Character::Character( const Character& other ) : _name(other._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i] != NULL)
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
}

Character&	Character::operator=( const Character& other )
{
	if (this != &other)
	{
		this->_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i] != NULL)
				delete this->_inventory[i];
			this->_inventory[i] = NULL;
			if (other._inventory[i] != NULL)
				this->_inventory[i] = other._inventory[i]->clone();
		}
	}
	return (*this);
}

Character::~Character( void )
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];		
	}
}

const std::string&	Character::getName() const
{
	return (this->_name);
}

void				Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			return ;
		}
	}
}

void				Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		this->_inventory[idx] = NULL;
	}
}

void				Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
	{
		if (this->_inventory[idx] != NULL)
		{
			this->_inventory[idx]->use(target);
		}
	}
}

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
		if (other._inventory != NULL)
			this->_inventory[i] = other._inventory[i];
	}
}

Character	Character::operator=( const Character& other );
virtual Character::~Character( void );

const std::string&	Character::getName() const;
void				Character::equip(AMateria* m);
void				Character::unequip(int idx);
void				Character::use(int idx, ICharacter& target);

private:
std::string			_name;
AMateria*			_inventory[4];
#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
	for (int i = 0; i < 4; i++)
		this->_learnInventory[i] = NULL;
}

MateriaSource::MateriaSource( const MateriaSource& other )
{
	for (int i = 0; i < 4; i++)
	{
		if (other._learnInventory[i] != NULL)
			this->_learnInventory[i] = other._learnInventory[i]->clone();
		else
			this->_learnInventory[i] = NULL;
	}
}

MateriaSource&	MateriaSource::operator=( const MateriaSource& other )
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_learnInventory[i] != NULL)
				delete this->_learnInventory[i];
			this->_learnInventory[i] = NULL;
			if (other._learnInventory[i] != NULL)
				this->_learnInventory[i] = other._learnInventory[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource( void )
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_learnInventory[i])
			delete this->_learnInventory[i];
	}
}

void		MateriaSource::learnMateria( AMateria* m )
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->_learnInventory[i] == NULL)
		{
			this->_learnInventory[i] = m;
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria( const std::string& type )
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_learnInventory[i] && this->_learnInventory[i]->getType() == type)
		{
			return (this->_learnInventory[i]->clone());
		}
	}
	return (0);
}

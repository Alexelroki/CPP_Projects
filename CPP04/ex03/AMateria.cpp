#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria( const std::string& type ) : _type(type) {}

AMateria::AMateria( const AMateria& other ) : _type(other._type) {}

AMateria&	AMateria::operator=( const AMateria& other )
{
	if (this != &other)
	{
		this->_type = other._type
	}
	return (*this);
}

AMateria::~AMateria( void ) {}

const std::string&	AMateria::getType( void ) const
{
	return (this->_type);
}

void	AMateria::use(ICharacter& target)
{
	(void)target; // Default behavior does nothing
	//std::cout << "* shoots any abstract materia at " << target " *" << std::endl;
}

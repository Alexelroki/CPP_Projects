#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie( void ) : _name("") {}
Zombie::Zombie( std::string name ): _name(name) {}
Zombie::~Zombie()
{
	std::cout << _name << " was killed." << std::endl;
}

void	Zombie::setName( std::string name )
{
	_name = name;
}

void	Zombie::announce( void )
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

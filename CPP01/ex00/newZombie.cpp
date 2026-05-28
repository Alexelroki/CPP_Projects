#include "Zombie.hpp"

Zombie*	newZombie( std::string name )
{
	Zombie* hippie_zombie = new Zombie( name );
	return (hippie_zombie);
}

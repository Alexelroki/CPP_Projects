#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	stackie_zombie = Zombie( name );
	stackie_zombie.announce();
}

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*hippie_zombie = newZombie( "Patrick" );
	hippie_zombie->announce();
	randomChump( "Jackson" );
	randomChump( "Mary Jane" );
	hippie_zombie->announce();
	delete hippie_zombie;
}

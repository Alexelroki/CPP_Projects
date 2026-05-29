#include "Zombie.hpp"

int	main(void)
{
	int		N = 5;
	std::string	horde_name = "Hungry of brains";
	Zombie*		zombie_horde = zombieHorde( N, horde_name );

	for (int i = 0; i < N; i++)
		zombie_horde[i].announce();
	delete[] zombie_horde;
}

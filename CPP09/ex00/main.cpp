//#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int	main(int argc, char** argv)
{
	(void)argv;
	try
	{
		if (argc != 2)
		{
			throw std::invalid_argument("muy mal tío, dame un archivo al menos...");
		}
		std::ifstream	file(argv[1]);
		if (!file.is_open())
			throw std::runtime_error("el archivo no se pudo abrir.");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}

	return (0);
}

#include <iostream>
#include <cctype>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; argv[i][j]; j++)
			{
				char c = (char)std::toupper(argv[i][j]);
				std::cout << c;
			}
		}
		std::cout << std::endl;
	}
	return (0);
}

--------- ///* Otra versión, sin el bucle anidado, pero con un comportamiento diferente (no convierte a mayúscula, sino que imprime tal cual) POR COMPLETAR*/
std::string toUpper(std::string str)
{
	std::string result;
	for (size_t i = 0; i < str.length(); i++)
		result += std::toupper(str[i]);
	return result;
}
int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::cout << std::toupper(argv[i]) << " ";
		}
		std::cout << std::endl;
	}
	return (0);
}

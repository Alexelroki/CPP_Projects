#include "FileReplacer.hpp"
#include <iostream>

int	main( int argc, char **argv )
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./sed_is_for_losers <filename> <string1> <string2>" << std::endl;
		return (1);
	}
	FileReplacer replacer( argv[1], argv[2], argv[3] );
	if (!replacer.execute())
		return (1);
	return (0);
}

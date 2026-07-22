#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib> // std::strtod
#include <cmath> // std::isnan, std::isinf
#include <limits> // std::numeric_limits
#include <iomanip> // std::fixed, std::setprecision

ScalarConverter::ScalarConverter( void ) {}

ScalarConverter::ScalarConverter( const ScalarConverter& other )
{
	(void)other;
}

ScalarConverter&	ScalarConverter::operator=( const ScalarConverter& other )
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter( void ) {}


void		ScalarConverter::convert(const std::string& str)
{
	if (str.length() == 1 && !std::isdigit(str[0]))
	{
		char	c = str[0];

		std::cout << "char: '" << c << "'\n";
		std::cout << "int: " << static_cast<int>(c) << "\n";
		std::cout << "float: " << static_cast<float>(c) << "\n";
		std::cout << "double: " << static_cast<double>(c) << "\n";
		return ;
	}
	char*	endPtr = NULL;
	double	val = std::strtod(str.c_str(), &endPtr);

	if (endPtr == str.c_str() || (*endPtr != '\0' && *endPtr != 'f') || (*endPtr == 'f' && *(endPtr + 1) != '\0'))
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
		return ;
	}
	// Char
	if (val != val || val < 0 || val > 127)
	{
		std::cout << "char: impossible\n";
	}
	else if (!std::isprint(static_cast<int>(val)))
	{
		std::cout << "char: Non displayable\n";
	}
	else
	{
		std::cout << "char: '" << static_cast<char>(val) << "'\n";
	}
	// Int
	if (val != val || val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
	{
		std::cout << "int: impossible\n";
	}
	else
	{
		std::cout << "int: " << static_cast<int>(val) << "\n";
	}
	// Add .0 decimal for floats and doubles
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(val) << "f\n";
	std::cout << "double: " << static_cast<double>(val) << "\n";
}


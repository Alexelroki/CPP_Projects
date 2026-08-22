#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cerrno>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& other )
{
	*this = other;
}

BitcoinExchange&	BitcoinExchange::operator=( const BitcoinExchange& other )
{
	if (this != &other)
		this->database_ = other.database_;
	return (*this);
}

BitcoinExchange::~BitcoinExchange( void ) {}

void	BitcoinExchange::trim( std::string& str ) const
{
	size_t	first = str.find_first_not_of(" \t\r\n");
	if (first == std::string::npos)
	{
		str = "";
		return ;
	}
	size_t	last = str.find_last_not_of(" \t\r\n");
	str = str.substr(first, (last - first + 1));
}

bool	BitcoinExchange::isLeapYear( int year ) const
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

bool	BitcoinExchange::isValidDate( const std::string& date) const
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	for (size_t i = 0; i < date.length(); ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return (false);
	}

	int	year = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8, 2).c_str());

	if (year < 1 || month < 1 || month > 12 || day < 1)
		return (false);

	int	daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2 && isLeapYear(year))
		daysInMonth[1] = 29;
	return (day <= daysInMonth[month - 1]);
}

bool	BitcoinExchange::isValidValue( const std::string& valStr, double& value) const
{
	char*	end;
	errno = 0;
	value = std::strtod(valStr.c_str(), &end);

	if (valStr.empty() || end == valStr.c_str() || *end != '\0'
		|| errno == ERANGE || value != value)
	{
		std::cerr << "Error: not a valid number." << '\n';
		return (false);
	}
	if (value < 0.0)
	{
		std::cerr << "Error: not a positive number." << '\n';
		return (false);
	}
	if (value > 1000.0)
	{
		std::cerr << "Error: number too large." << '\n';
		return (false);
	}
	return (true);
}

void BitcoinExchange::loadDatabase(const std::string& dbPath)
{
	std::ifstream	file(dbPath.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open database file.");

	std::string		line;

	if (!std::getline(file, line))
		throw std::runtime_error("Error: database is empty.");

	while (std::getline(file, line))
	{
		if (line.empty())
			continue ;
		size_t		commaPos = line.find(',');
		if (commaPos == std::string::npos)
			continue ;

		std::string	date = line.substr(0, commaPos);
		std::string	rateStr = line.substr(commaPos + 1);

		trim(date);
		trim(rateStr);

		char*		end;
		errno = 0;
		double		rate = std::strtod(rateStr.c_str(), &end);
		if (date.empty() || !isValidDate(date) || rateStr.empty()
			|| end == rateStr.c_str() || *end != '\0' || errno == ERANGE
			|| rate != rate || rate < 0.0)
			continue ;
		database_[date] = rate;
	}

	if (database_.empty())
		throw std::runtime_error("Error: no valid data loaded from database.");
}

void BitcoinExchange::processInput(const std::string& inputPath) const
{
	std::ifstream	file(inputPath.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open input file.");

	std::string		line;
	if (!std::getline(file, line))
		throw std::runtime_error("Error: input file is empty.");

	while (std::getline(file, line))
	{
		if (line.empty())
			continue ;

		size_t		pipePos = line.find('|');
		if (pipePos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << '\n';
			continue ;
		}

		std::string	date = line.substr(0, pipePos);
		std::string	valStr = line.substr(pipePos + 1);

		trim(date);
		trim(valStr);

		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << date << '\n';
			continue ;
		}

		double		value = 0.0;
		if (!isValidValue(valStr, value))
			continue ;

		std::map<std::string, double>::const_iterator	it = database_.upper_bound(date);

		if (it == database_.begin())
		{
			std::cerr << "Error: date is older than any recorded data => " << date << '\n';
			continue;
		}
		--it;

		std::cout << date << " => " << value << " = " << (value * it->second) << '\n';
	}
}

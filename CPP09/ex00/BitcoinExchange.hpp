#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>

class BitcoinExchange
{
	public:
		// Orthodox Canonical Form
		BitcoinExchange( void );
		BitcoinExchange( const BitcoinExchange& other );
		BitcoinExchange&	operator=( const BitcoinExchange& other );
		~BitcoinExchange( void );

		void	loadDatabase( const std::string& dbPath );
		void	processInput( const std::string& inputPath ) const;

	private:
		std::map<std::string, double>	database_;

		bool	isValidDate( const std::string& date) const;
		bool	isValidValue( const std::string& valStr, double& value) const;
		bool	isLeapYear( int year ) const;
		void	trim( std::string& str ) const;
};

#endif

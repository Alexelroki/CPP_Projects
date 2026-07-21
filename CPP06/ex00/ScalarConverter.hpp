#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter
{
	public:
		static void		convert(const std::string& str);
	private:
		// Orthodox Canonical Form
		ScalarConverter( void );
		ScalarConverter( const ScalarConverter& other );
		ScalarConverter		operator=( const ScalarConverter& other );
		~ScalarConverter( void );
};

#endif

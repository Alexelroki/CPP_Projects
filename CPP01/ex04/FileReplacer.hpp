#ifndef FILEREPLACER_HPP
# define FILEREPLACER_HPP

# include <string>

class FileReplacer
{
	private:
		const std::string	_filename;
		const std::string	_s1;
		const std::string	_s2;

		std::string		_replaceLine( const std::string& line );

	public:
		FileReplacer
		(
			const std::string& filename,
			const std::string& s1,
			const std::string& s2
		);
		~FileReplacer();

		bool	execute( void );
};

#endif

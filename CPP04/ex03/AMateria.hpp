#ifndef	AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

class	ICharacter; // Forward declaration to avoid cross-inclusion issues

class	AMateria
{
	public:
		AMateria( const std::string& type );
		AMateria( const AMateria& other );
		AMateria&	operator=( const AMateria& other );
		virtual ~AMateria( void );

		// Getter
		const std::string&	getType( void ) const;

		// Functions
		virtual AMateria*	clone( void ) const = 0;
		virtual void		use(ICharacter& target);

	protected:
		std::string			_type;
};

#endif
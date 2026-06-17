#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
	public:
		// Orthodox Canonical Form
		Character( const std::string& name );
		Character( const Character& other );
		Character&	operator=( const Character& other );
		virtual ~Character( void );

		// Contract rules
		const std::string&	getName( void ) const;
		void				equip( AMateria* m );
		void				unequip( int idx );
		void				use( int idx, ICharacter& target );

		// Getter
		AMateria*			getMateria( int idx ) const;

	private:
		std::string			_name;
		AMateria*			_inventory[4];
};

#endif
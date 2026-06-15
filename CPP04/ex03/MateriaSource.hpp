#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*	_learnInventory[4];

	public:
		// Orthodox Canonical Form
		MateriaSource( void );
		MateriaSource( const MateriaSource& other );
		MateriaSource&	operator=( const MateriaSource& other );
		~MateriaSource( void );

		// Contract Funtions
		void		learnMateria( AMateria* m );
		AMateria*	createMateria( const std::string& type );
};

#endif
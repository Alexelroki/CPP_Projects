#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

// FragTrap virtually and publicly inherits from ClapTrap
class FragTrap : virtual public ClapTrap
{
	public:
		// Orthodox Canonical Form
		FragTrap( void );
		FragTrap( const std::string& name );
		FragTrap( const FragTrap& other );
		FragTrap& operator=( const FragTrap& other );
		virtual ~FragTrap( void );

		// Unique special capability
		void    highFivesGuys( void );
};

#endif
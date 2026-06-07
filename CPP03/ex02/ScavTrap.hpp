#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

// ScavTrap publicly inherits from ClapTrap
class ScavTrap : public ClapTrap
{
	public:
		// Orthodox Canonical Form
		ScavTrap( void );
		ScavTrap( const std::string& name );
		ScavTrap( const ScavTrap& other );
		ScavTrap& operator=( const ScavTrap& other );
		virtual ~ScavTrap( void );

		// We redefined attack because the statement says it has its own message
		void    attack( const std::string& target );
		
		// ScavTrap's unique special capability
		void    guardGate( void );
};

#endif
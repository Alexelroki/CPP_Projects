#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

// DiamondTrap virtually and publicly inherits from BOTH: FragTrap and ScavTrap
class DiamondTrap : public FragTrap, ScavTrap
{
	private:
		std::string	_name;
	public:
		// Orthodox Canonical Form
		DiamondTrap( void );
		DiamondTrap( const std::string& name );
		DiamondTrap( const DiamondTrap& other );
		DiamondTrap&	operator=( const DiamondTrap& other );
		~DiamondTrap( void );

		// We need to choose the FragTrap implementation
		void	attack( const std::string& target );

		// DiamondTrap special capability
		void	whoAmI( void );
};

#endif
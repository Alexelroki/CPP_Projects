DiamondTrap::DiamondTrap( void )
	: ClapTrap("Default_clap_name"), ScavTrap(), FragTrap()
{
	this->name = "Default";
}

DiamondTrap::DiamondTrap( const std::string& name );
DiamondTrap::DiamondTrap( const DiamondTrap& other );
DiamondTrap&	DiamondTrap::operator=( const DiamondTrap& other );
DiamondTrap::~DiamondTrap( void );

// We need to choose the FragTrap implementation
void	DiamondTrap::attack( const std::string& target );

// DiamondTrap special capability
void	DiamondTrap::whoAmI( void );
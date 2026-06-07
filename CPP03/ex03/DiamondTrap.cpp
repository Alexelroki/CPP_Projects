DiamondTrap::DiamondTrap( void )
	: ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(), _name("Default")
{
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( const std::string& name )
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) 
{
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap name constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap& other )
	: ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	*this = other;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=( const DiamondTrap& other )
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_name = other._name;
	}
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

// We need to choose the FragTrap implementation
void	DiamondTrap::attack( const std::string& target )
{
	ScavTrap::attack(target);
}

// DiamondTrap special capability
void	DiamondTrap::whoAmI( void );
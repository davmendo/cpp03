#include "DiamondTrap.hpp"

/*
** The virtual base ClapTrap is constructed once, by the most-derived class
** (DiamondTrap). The ": ClapTrap(...)" calls inside FragTrap/ScavTrap are
** ignored here, so DiamondTrap is responsible for it.
**
** Init-list order must match construction order (virtual base first, then the
** base-list order FragTrap -> ScavTrap) to avoid -Wreorder under -Wall.
**
** Stats per subject: hitPoints (FragTrap = 100), energyPoints (ScavTrap = 50),
** attackDamage (FragTrap = 30). They are set explicitly in the body so the
** result does not depend on which base constructor ran last.
*/

DiamondTrap::DiamondTrap(void) :
	ClapTrap("Default_clap_name"),
	FragTrap(),
	ScavTrap(),
	_name("Default")
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) :
	ClapTrap(name + "_clap_name"),
	FragTrap(name),
	ScavTrap(name),
	_name(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << "DiamondTrap " << _name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) :
	ClapTrap(other),
	FragTrap(other),
	ScavTrap(other),
	_name(other._name)
{
	std::cout << "DiamondTrap " << _name << " copy constructor called" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap " << _name << " copy assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		_name = other._name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << _name << " destructor called" << std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << _name
		<< ", ClapTrap name: " << ClapTrap::_name << std::endl;
}

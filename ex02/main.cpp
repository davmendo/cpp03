#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	std::cout << "===== FragTrap construction chain =====" << std::endl;
	{
		FragTrap	frag("FR4G-TP");

		std::cout << "\n--- FragTrap actions ---" << std::endl;
		frag.attack("the boss");
		frag.takeDamage(55);
		frag.beRepaired(20);
		frag.highFivesGuys();

		std::cout << "\n--- destruction chain (FragTrap then ClapTrap) ---" << std::endl;
	}

	std::cout << "\n===== ScavTrap still works alongside FragTrap =====" << std::endl;
	{
		ScavTrap	scav("SC4V-TP");
		scav.attack("the gate");
		scav.guardGate();
	}

	std::cout << "\n===== FragTrap copy semantics =====" << std::endl;
	{
		FragTrap	original("Origin");
		FragTrap	copy(original);
		FragTrap	assigned("Assigned");
		assigned = original;
		copy.highFivesGuys();
	}

	return (0);
}

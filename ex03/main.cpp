#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	std::cout << "===== DiamondTrap construction (ClapTrap built ONCE) =====" << std::endl;
	{
		DiamondTrap	diamond("Diamond");

		std::cout << "\n--- whoAmI: own name vs ClapTrap name ---" << std::endl;
		diamond.whoAmI();

		std::cout << "\n--- inherited abilities ---" << std::endl;
		diamond.attack("the dummy");      // from ScavTrap
		diamond.guardGate();              // from ScavTrap
		diamond.highFivesGuys();          // from FragTrap
		diamond.takeDamage(40);           // from ClapTrap
		diamond.beRepaired(10);           // from ClapTrap

		std::cout << "\n--- destruction chain (Diamond -> Scav -> Frag -> Clap) ---" << std::endl;
	}

	std::cout << "\n===== DiamondTrap copy semantics =====" << std::endl;
	{
		DiamondTrap	original("Origin");
		DiamondTrap	copy(original);
		copy.whoAmI();

		DiamondTrap	assigned("Assigned");
		assigned = original;
		assigned.whoAmI();
	}

	return (0);
}

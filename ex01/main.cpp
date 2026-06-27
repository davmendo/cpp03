#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << "===== ClapTrap on its own =====" << std::endl;
	{
		ClapTrap	clap("CL4P-TP");
		clap.attack("a wild target");
		clap.takeDamage(3);
		clap.beRepaired(1);
	}

	std::cout << "\n===== ScavTrap construction chain =====" << std::endl;
	{
		ScavTrap	scav("SC4V-TP");

		std::cout << "\n--- ScavTrap actions ---" << std::endl;
		scav.attack("the intruder");
		scav.takeDamage(40);
		scav.beRepaired(15);
		scav.guardGate();

		std::cout << "\n--- destruction chain (ScavTrap then ClapTrap) ---" << std::endl;
	}

	std::cout << "\n===== ScavTrap copy semantics =====" << std::endl;
	{
		ScavTrap	original("Origin");
		ScavTrap	copy(original);
		ScavTrap	assigned("Assigned");
		assigned = original;
		copy.guardGate();
	}

	return (0);
}

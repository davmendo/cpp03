#include "ClapTrap.hpp"

int	main(void)
{
	std::cout << "===== Construction =====" << std::endl;
	ClapTrap	a("CL4P-TP");
	ClapTrap	b("Robot");

	std::cout << "\n===== Normal combat =====" << std::endl;
	a.attack("Robot");
	b.takeDamage(0);
	b.takeDamage(4);
	b.beRepaired(2);

	std::cout << "\n===== Draining all energy (10 attacks) =====" << std::endl;
	for (int i = 0; i < 11; i++)
		a.attack("the air");

	std::cout << "\n===== No energy left: can't act =====" << std::endl;
	a.beRepaired(5);

	std::cout << "\n===== Destroying a target (overkill) =====" << std::endl;
	b.takeDamage(100);
	b.takeDamage(5);
	b.beRepaired(5);

	std::cout << "\n===== Copy semantics =====" << std::endl;
	ClapTrap	c(a);
	ClapTrap	d("Temp");
	d = a;

	std::cout << "\n===== Destruction (reverse order) =====" << std::endl;
	return (0);
}

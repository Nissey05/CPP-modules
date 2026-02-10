#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("Clappy");
	a.attack("Orhan");
	a.beRepaired(0);
	a.takeDamage(50000);
	a.attack("Orhan");
	a.beRepaired(5);
}
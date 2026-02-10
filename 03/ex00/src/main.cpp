#include "ClapTrap.hpp"
#include "colors.h"

int main(void)
{
	std::cout << BOLD_RED_BACK << "ClapTrap:" << RESET << std::endl;
	ClapTrap a("Clappy");
	a.attack("Orhan");
	a.beRepaired(0);
	a.takeDamage(50000);
	a.attack("Orhan");
}
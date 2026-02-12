#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "colors.h"

int main(void)
{
	std::cout << BOLD_RED_BACK << "ClapTrap:" << RESET << std::endl;
	ClapTrap a("Clappy");
	a.attack("Orhan");
	a.beRepaired(0);
	a.takeDamage(50000);
	a.attack("Orhan");
	std::cout << BOLD_RED_BACK << "ScavTrap:" << RESET << std::endl;
	ScavTrap b("pieter");
	b.attack("abcd");
	b.guardGate();
	b.beRepaired(69);
	b.takeDamage(420);
	std::cout << BOLD_RED_BACK << "FragTrap:" << RESET << std::endl;
	FragTrap c("Aardappel");
	c.attack("a");
	c.highFivesGuys();
	std::cout << BOLD_RED_BACK << "Destructors:" << RESET << std::endl;
}
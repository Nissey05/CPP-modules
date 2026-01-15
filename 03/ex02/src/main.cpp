#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap a("Clappy");
	a.attack("Orhan");
	ScavTrap b("pieter");
	b.attack("abcd");
}
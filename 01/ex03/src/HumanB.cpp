#include "HumanB.hpp"

HumanB::HumanB(std::string name)
: name(name), weapon(NULL)
{}

HumanB::~HumanB(void) {
}

void HumanB::attack(void) {
	if (!weapon)
		std::cout << name << " attacks without a weapon" << std::endl;
	else
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon *weapon) {
	this->weapon =  weapon;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->weapon =  &weapon;
}
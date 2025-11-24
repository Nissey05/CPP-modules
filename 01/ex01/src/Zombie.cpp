#include "Zombie.hpp"

Zombie::Zombie(void){
}

Zombie::~Zombie(void){
	std::cout << name << std::endl;
}

void Zombie::announce(void){
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name){
	this->name = name;
}
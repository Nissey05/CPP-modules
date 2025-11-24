#include "Zombie.h"

int main(void)
{
	Zombie a("a");
	a.announce();
	Zombie *b = newZombie("b");
	b->announce();
	delete(b);
	randomChump("d");
	delete(newZombie("e"));
}
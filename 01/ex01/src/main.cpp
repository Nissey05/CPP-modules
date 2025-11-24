#include "Zombie.h"

int main(void)
{
	int N = 5;
	Zombie *horde = zombieHorde(N, "Rozz");
	for (int i = 0; horde && i < N + 1; i++)
		horde[i].announce();
	N = 15;
	Zombie *horde2 = zombieHorde(N, "Fred");
	for (int i = 0; horde2 && i < N + 1; i++)
		horde2[i].announce();
	N = -1;
	Zombie *horde3 = zombieHorde(N, "Ruby");
	for (int i = 0; horde3 && i < N + 1; i++)
		horde3[i].announce();
	horde[0].announce();
	horde2[1].announce();
}
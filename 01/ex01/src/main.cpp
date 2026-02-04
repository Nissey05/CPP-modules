#include "Zombie.h"

int main(void)
{
	int N = 5;
	std::cout << BOLD_RED << "Creating " << N << " zombies with name Rozz." << RESET << std::endl;
	Zombie *horde = zombieHorde(N, "Rozz");
	std::cout << GREEN << "Announcing all of horde." << RESET << std::endl;
	for (int i = 0; horde && i < N; i++)
		horde[i].announce();
	N = 15;
	std::cout << std::endl << BOLD_RED << "Creating " << N << " zombies with name Fred." << RESET << std::endl;
	Zombie *horde2 = zombieHorde(N, "Fred");
	std::cout << GREEN << "Announcing all of horde2." << RESET << std::endl;
	for (int i = 0; horde2 && i < N; i++)
		horde2[i].announce();
	N = -1;
	std::cout << std::endl << BOLD_RED << "Creating " << N << " zombies with name Ruby." << RESET << std::endl;
	Zombie *horde3 = zombieHorde(N, "Ruby");
	std::cout << GREEN << "Announcing all of horde3." << RESET << std::endl << std::endl;
	for (int i = 0; horde3 && i < N; i++)
		horde3[i].announce();
	std::cout << std::endl << GREEN << "Announcing horde[0]." << RESET << std::endl;
	horde[0].announce();
	std::cout << std::endl << GREEN << "Announcing horde2[1]." << RESET << std::endl;
	horde2[1].announce();
	delete[] horde;
	delete[] horde2;
}
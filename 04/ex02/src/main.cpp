#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"

int main(void)
{
	Cat *kitty = new Cat("kitty");
	kitty->makeSound();
	Cat *petertje = new Cat(*kitty);
	petertje->makeSound();
	Dog *dogster = new Dog("Dogster");
	dogster->makeSound();
	delete kitty;
	delete petertje;
	delete dogster;
}
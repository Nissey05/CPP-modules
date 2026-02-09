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
	dogster->setIdea(1, "I love cheese");
	Dog *doggusy = new Dog();
	*doggusy = *dogster;
	doggusy->makeSound();
	dogster->setIdea(2, "I love cheese more");
	delete dogster;
	std::cout << doggusy->getIdea(1) << std::endl;
	std::cout << doggusy->getIdea(100) << std::endl;
	delete kitty;
	delete petertje;
	delete doggusy;
}
#include "Cat.hpp"
#include "Dog.hpp"
#include "colors.h"

int main(void)
{
	std::cout << BOLD_RED_BACK << "Kitty: " << RESET << std::endl;
	Cat *kitty = new Cat("kitty");
	kitty->makeSound();
	std::cout << BOLD_RED_BACK << "petertje (copy of kitty): " << RESET << std::endl;
	Cat *petertje = new Cat(*kitty);
	petertje->makeSound();
	std::cout << BOLD_RED_BACK << "Dogster: " << RESET << std::endl;
	Dog *dogster = new Dog("Dogster");
	dogster->makeSound();
	dogster->setIdea(1, "I love cheese");
	std::cout << BOLD_RED_BACK << "Dogussy (copy of dogster): " << RESET << std::endl;
	Dog *doggusy = new Dog();
	*doggusy = *dogster;
	doggusy->makeSound();
	dogster->setIdea(2, "I love cheese more");
	std::cout << BOLD_RED_BACK << "dogster destructor: " << RESET << std::endl;
	delete dogster;
	std::cout << BOLD_BRIGHT_WHITE << "doggusy->getIdea(1): " << doggusy->getIdea(1) << RESET << std::endl;
	std::cout << BOLD_BRIGHT_WHITE << "doggusy->getIdea(100): " << doggusy->getIdea(100) << RESET << std::endl;
	std::cout << BOLD_RED_BACK << "Destructors: " << RESET << std::endl;
	delete kitty;
	std::cout << std::endl;
	delete petertje;
	std::cout << std::endl;
	delete doggusy;
}
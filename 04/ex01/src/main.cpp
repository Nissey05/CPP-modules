#include "Cat.hpp"
#include "Dog.hpp"
#include "colors.h"

int main(void)
{
	std::cout << BOLD_RED_BACK << "Array construction:" << RESET << std::endl;
	Animal *Animals[8] =
	{ new Cat, new Dog, new Cat, new Dog, new Cat, new Cat, new Dog, new Dog };
	std::cout << BOLD_RED_BACK << "cat1 construction:" << RESET << std::endl;
	Cat *cat1 = new Cat("Y'shtola");
	std::cout << std::endl;
	cat1->setIdea(0, "Draw Card");
	cat1->setIdea(1, "Deal 2 Heal 2");
	std::cout << BOLD_RED_BACK << "cat2 construction:" << RESET << std::endl;
	Cat *cat2 = new Cat(*cat1);
	std::cout << std::endl;
	cat2->makeSound();
	cat1->setIdea(1, "gg");
	std::cout << BOLD_BRIGHT_WHITE << "cat1->getIdea(1): " << cat1->getIdea(1) << RESET << std::endl;
	std::cout << BOLD_BRIGHT_WHITE << "cat2->getIdea(1): " << cat2->getIdea(1) << RESET << std::endl;
	std::cout << BOLD_RED_BACK << "cat1 destruction:" << RESET << std::endl;
	delete cat1;
	std::cout << std::endl;
	std::cout << BOLD_RED_BACK << cat2->getIdea(1) << RESET << std::endl;
	std::cout << BOLD_RED_BACK << "cat2 destruction:" << RESET << std::endl;
	delete cat2;
	std::cout << BOLD_RED_BACK << "array destruction:" << RESET << std::endl;
	for (int i = 0; i < 8; i++)\
	{
		delete Animals[i];
		std::cout << std::endl;
	}
}
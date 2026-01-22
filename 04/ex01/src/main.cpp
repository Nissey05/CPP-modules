#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"

int main(void)
{
	std::cout << "---array construction-----------" << std::endl;
	Animal *Animals[8] =
	{ new Cat, new Dog, new Cat, new Dog, new Cat, new Cat, new Dog, new Dog };
	std::cout << "--------------------------------\n" << std::endl;
	std::cout << "---cat1 construction------------" << std::endl;
	Cat *cat1 = new Cat("Y'shtola");
	std::cout << "--------------------------------\n" << std::endl;
	cat1->setIdea(0, "Draw Card");
	cat1->setIdea(1, "Deal 2 Heal 2");
	std::cout << "---cat2 construction------------" << std::endl;
	Cat *cat2 = new Cat(*cat1);
	std::cout << "--------------------------------\n" << std::endl;
	cat2->makeSound();
	cat1->setIdea(1, "gg");
	std::cout << cat1->getIdea(1) << std::endl;
	std::cout << cat2->getIdea(1) << std::endl;
	std::cout << "---cat1 destruction------------" << std::endl;
	delete cat1;
	std::cout << "--------------------------------\n" << std::endl;
	std::cout << cat2->getIdea(1) << std::endl;
	std::cout << "---cat2 destruction-------------" << std::endl;
	delete cat2;
	std::cout << "--------------------------------\n" << std::endl;
	std::cout << "---array destruction------------" << std::endl;
	for (int i = 0; i < 8; i++)
		delete Animals[i];
	std::cout << "--------------------------------\n" << std::endl;
}
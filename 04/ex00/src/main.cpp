#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "colors.h"

int main(void)
{
	std::cout << BOLD_RED_BACK << "Subject tests:" << RESET << std::endl;
	std::cout << BOLD_RED_BACK << "	Constructors:" << RESET << std::endl;
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << BOLD_RED_BACK << "	tests:" << RESET << std::endl;
	std::cout << BOLD_BRIGHT_WHITE << "Dog->getType(): " << RESET;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << BOLD_BRIGHT_WHITE << "Cat->getType(): " << RESET;
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();
	dog->makeSound();
	meta->makeSound();
	std::cout << BOLD_RED_BACK << "	destructors:" << RESET << std::endl;
	delete meta;
	std::cout << std::endl;
	delete dog;
	std::cout << std::endl;
	delete cat;
	std::cout << BOLD_RED_BACK << "Subject tests with WrongAnimals:" << RESET << std::endl;
	std::cout << BOLD_RED_BACK << "	Constructors:" << RESET << std::endl;
	const WrongAnimal* wrongmeta = new WrongAnimal();
	const WrongAnimal* wrongcat = new WrongCat();
	std::cout << BOLD_RED_BACK << "	tests:" << RESET << std::endl;
	std::cout << BOLD_BRIGHT_WHITE << "wrongcat->getType(): " << RESET;
	std::cout << wrongcat->getType() << " " << std::endl;
	wrongcat->makeSound();
	wrongmeta->makeSound();
	std::cout << BOLD_RED_BACK << "	destructors:" << RESET << std::endl;
	delete wrongmeta;
	std::cout << std::endl;
	delete wrongcat;
	std::cout << BOLD_RED_BACK << "My tests:" << RESET << std::endl;
	Animal *diff = new Dog("Dogster");
	diff->makeSound();
	std::cout << BOLD_BRIGHT_WHITE << "diff->getType(): " << diff->getType() << RESET << std::endl;
	delete diff;
	diff = new Cat("Catussy");
	diff->makeSound();
	std::cout << BOLD_BRIGHT_WHITE << "diff->getType(): " << diff->getType() << RESET << std::endl;
	delete diff;
	diff = new Animal("T-rex");
	diff->makeSound();
	std::cout << BOLD_BRIGHT_WHITE << "diff->getType(): " << diff->getType() << RESET << std::endl;
	delete diff;
}
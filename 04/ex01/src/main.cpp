#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"

int main(void)
{
	Animal *ani = new Cat();
	Animal *ani2 = new Dog();
	ani->makeSound();
	ani->brain->setIdea();
	ani2->makeSound();
	Animal *ani3 = new Cat(dynamic_cast<const Cat&>(*ani));
	delete ani;
	ani3->makeSound();
	delete ani2;
}
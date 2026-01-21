#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"


int main(void)
{
	Animal *ani = new Cat();
	Animal *ani2 = new Dog();
	ani->makeSound();
	ani2->makeSound();
}
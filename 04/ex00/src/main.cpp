#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongCat.hpp"

int main(void)
{
	Animal *ani = new Cat();
	Animal *ani2 = new Dog();
	WrongAnimal *wani = new WrongCat();
	ani->makeSound();
	ani2->makeSound();
	wani->makeSound();
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:18:25 by nhendrik          #+#    #+#             */
/*   Updated: 2026/01/21 20:51:39 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"
#include <random>

Dog::Dog() :
Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string name) :
Animal(name)
{
	std::cout << "Dog name constructor called" << std::endl;
}

Dog::Dog(const Dog& copy) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = copy;
}

Dog::~Dog() {
	std::cout << "Dog default destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& copy) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	this->type = copy.type;
	return (*this);
}


void Dog::makeSound(void) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> bark(1, 4);

	for (int c = bark(gen); c > 0; c--)
		std::cout << "Woof!" << std::endl;
}
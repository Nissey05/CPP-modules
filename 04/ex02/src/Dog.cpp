/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:18:25 by nhendrik          #+#    #+#             */
/*   Updated: 2026/01/22 21:22:19 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"
#include "../inc/RNG.h"

Dog::Dog() :
Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(std::string name) :
Animal(name)
{
	std::cout << "Dog name constructor called" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog& copy) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain();
	*this = copy;
}

Dog::~Dog() {
	delete brain;
	std::cout << "Dog default destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& copy) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	this->type = copy.type;
	*this->brain = *copy.brain;
	return (*this);
}

void Dog::makeSound(void) {
	for (int c = RNG(1, 4); c > 0; c--)
		std::cout << "Woof!" << std::endl;
}

void Dog::setIdea(int i, std::string idea)
{
	if (i < 100)
		brain->setIdea(i, idea);
}

std::string Dog::getIdea(int i)
{
	if (i < 100)
		return (brain->getIdea(i));
	return ("No thoughts here");
}
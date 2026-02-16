/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:18:25 by nhendrik          #+#    #+#             */
/*   Updated: 2026/02/16 22:04:00 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "RNG.h"
#include "colors.h"

Dog::Dog() :
Animal("Dog")
{
	std::cout << BOLD_BRIGHT_CYAN << "Dog default constructor called" << RESET << std::endl;
	this->brain = new Brain();
}

Dog::Dog(std::string name) :
Animal(name)
{
	std::cout << BOLD_BRIGHT_CYAN << "Dog name constructor called" << RESET << std::endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog& copy) :
Animal(copy)
{
	std::cout << BOLD_BRIGHT_CYAN << "Dog copy constructor called" << RESET << std::endl;
	this->brain = new Brain();
	*this = copy;
}

Dog::~Dog() {
	delete brain;
	std::cout << BOLD_BRIGHT_CYAN << "Dog default destructor called" << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& copy) {
	std::cout << BOLD_BRIGHT_CYAN << "Dog copy assignment operator called" << RESET << std::endl;
	if (&copy == this)
		return (*this);
	this->type = copy.type;
	*this->brain = *copy.brain;
	return (*this);
}

void Dog::makeSound(void) const {
	for (int c = RNG(1, 4); c > 0; c--)
		std::cout << BOLD_BRIGHT_CYAN << "Woof!" << RESET << std::endl;
}

void Dog::setIdea(int i, std::string idea)
{
	if (i < 100)
		brain->setIdea(i, idea);
}

std::string Dog::getIdea(int i) const
{
	if (i < 100 && !brain->getIdea(i).empty())
		return (brain->getIdea(i));
	return ("No thoughts here");
}
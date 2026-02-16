/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:19:50 by nhendrik          #+#    #+#             */
/*   Updated: 2026/02/16 22:05:47 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "RNG.h"
#include "colors.h"

Cat::Cat() :
Animal("Cat")
{
	std::cout << BOLD_BRIGHT_MAGENTA << "Cat default constructor called" << RESET << std::endl;
	this->brain = new Brain();
}

Cat::Cat(std::string name) :
Animal(name)
{
	std::cout << BOLD_BRIGHT_MAGENTA << "Cat name constructor called" << RESET << std::endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat& copy) :
Animal(copy)
{
	std::cout << BOLD_BRIGHT_MAGENTA << "Cat copy constructor called" << RESET << std::endl;
	this->brain = new Brain();
	*this = copy;
}

Cat::~Cat() {
	delete brain;
	std::cout << BOLD_BRIGHT_MAGENTA << "Cat default destructor called" << RESET << std::endl;
}

Cat& Cat::operator=(const Cat& copy) {
	std::cout << BOLD_BRIGHT_MAGENTA << "Cat copy assignment operator called" << RESET << std::endl;
	if (&copy == this)
		return (*this);
	this->type = copy.type;
	*this->brain = *copy.brain;
	return (*this);
}

void Cat::makeSound(void) const {
	std::cout << BOLD_BRIGHT_MAGENTA << "M";
	int i = RNG(2, 7);
	while (i > 0)
	{
		std::cout << "e";
		i--;
	}
	i = RNG(3, 10);
	while (i > 0)
	{
		std::cout << "o";
		i--;
	}
	std::cout << "w";
	i = RNG(0, 5);
	while (i > 0)
	{
		std::cout << ".";
		i--;
	}
	std::cout << RESET << std::endl;
}

void Cat::setIdea(int i, std::string idea)
{
	if (i < 100)
		brain->setIdea(i, idea);
}

std::string Cat::getIdea(int i) const
{
	if (i < 100)
		return (brain->getIdea(i));
	return ("No thoughts here");
}
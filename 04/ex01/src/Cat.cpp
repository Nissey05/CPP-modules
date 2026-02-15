/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:19:50 by nhendrik          #+#    #+#             */
/*   Updated: 2026/02/15 23:31:19 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "RNG.hpp"
#include <random>

Cat::Cat() :
Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(std::string name) :
Animal(name)
{
	std::cout << "Cat name constructor called" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat& copy) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = new Brain();
	*this = copy;
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat default destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& copy) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	this->type = copy.type;
	*this->brain = *copy.brain;
	return (*this);
}

void Cat::makeSound(void) {
	std::cout << "M";
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
	std::cout << std::endl;
}

void Cat::setIdea(int i, std::string idea)
{
	if (i < 100)
		brain->setIdea(i, idea);
}

std::string Cat::getIdea(int i)
{
	if (i < 100)
		return (brain->getIdea(i));
	return ("No thoughts here");
}
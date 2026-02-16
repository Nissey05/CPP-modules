/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:18:25 by nhendrik          #+#    #+#             */
/*   Updated: 2026/02/16 21:01:26 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "RNG.h"
#include "colors.h"

Dog::Dog() :
Animal("Dog")
{
	std::cout << BOLD_BRIGHT_CYAN << "Dog default constructor called" << RESET << std::endl;
}

Dog::Dog(std::string name) :
Animal(name)
{
	std::cout << BOLD_BRIGHT_CYAN << "Dog name constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog& copy) :
Animal(copy)
{
	std::cout << BOLD_BRIGHT_CYAN << "Dog copy constructor called" << RESET << std::endl;
	*this = copy;
}

Dog::~Dog() {
	std::cout << BOLD_BRIGHT_CYAN << "Dog default destructor called" << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& copy) {
	std::cout << BOLD_BRIGHT_CYAN << "Dog copy assignment operator called" << RESET << std::endl;
	this->type = copy.type;
	return (*this);
}


void Dog::makeSound(void) const {
	for (int c = RNG(1, 4); c > 0; c--)
		std::cout << BOLD_BRIGHT_CYAN << "Woof!" << RESET << std::endl;
}
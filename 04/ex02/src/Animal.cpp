/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:15:56 by nhendrik          #+#    #+#             */
/*   Updated: 2026/02/16 22:01:56 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "colors.h"

Animal::Animal() :
type("Animal")
{
	std::cout << BOLD_BRIGHT_GREEN << "Animal default constructor called" << RESET << std::endl;
}

Animal::Animal(std::string name) :
type(name)
{
	std::cout << BOLD_BRIGHT_GREEN << "Animal name constructor called" << RESET << std::endl;
}

Animal::Animal(const Animal& copy) {
	std::cout << BOLD_BRIGHT_GREEN << "Animal copy constructor called" << RESET << std::endl;
	*this = copy;
}

Animal::~Animal() {
	std::cout << BOLD_BRIGHT_GREEN << "Animal default destructor called" << RESET << std::endl;
}

Animal& Animal::operator=(const Animal& copy) {
	std::cout << BOLD_BRIGHT_GREEN << "Animal copy assignment operator called" << RESET << std::endl;
	this->type = copy.type;
	return (*this);
}

std::string Animal::getType(void) const
{
	return (type);
}

void Animal::setType(const std::string name)
{
	type = name;
}
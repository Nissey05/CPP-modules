/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:15:56 by nhendrik          #+#    #+#             */
/*   Updated: 2026/01/21 20:48:31 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "colors.h"

WrongAnimal::WrongAnimal() :
type("WrongAnimal")
{
	std::cout << BOLD_BRIGHT_RED << "WrongAnimal default constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string name) :
type(name)
{
	std::cout << BOLD_BRIGHT_RED << "WrongAnimal name constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) {
	std::cout << BOLD_BRIGHT_RED << "WrongAnimal copy constructor called" << RESET << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal() {
	std::cout << BOLD_BRIGHT_RED << "WrongAnimal default destructor called" << RESET << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy) {
	std::cout << BOLD_BRIGHT_RED << "WrongAnimal copy assignment operator called" << RESET << std::endl;
	this->type = copy.type;
	return (*this);
}

void WrongAnimal::makeSound() const {
	std::cout << BOLD_BRIGHT_RED << "sus animal sound" << RESET << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (type);
}

void WrongAnimal::setType(const std::string name)
{
	type = name;
}
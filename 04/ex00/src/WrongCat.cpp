/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:19:50 by nhendrik          #+#    #+#             */
/*   Updated: 2026/01/21 20:45:07 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "colors.h"

WrongCat::WrongCat() :
WrongAnimal("WrongCat")
{
	std::cout << BOLD_BRIGHT_RED_UNDERLINE << "WrongCat default constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(std::string name) :
WrongAnimal(name)
{
	std::cout << BOLD_BRIGHT_RED_UNDERLINE << "WrongCat name constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) :
WrongAnimal(copy)
{
	std::cout << BOLD_BRIGHT_RED_UNDERLINE << "WrongCat copy constructor called" << RESET << std::endl;
	*this = copy;
}

WrongCat::~WrongCat() {
	std::cout << BOLD_BRIGHT_RED_UNDERLINE << "WrongCat default destructor called" << RESET << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& copy) {
	std::cout << BOLD_BRIGHT_RED_UNDERLINE << "WrongCat copy assignment operator called" << RESET << std::endl;
	this->type = copy.type;
	return (*this);
}

void WrongCat::makeSound(void) const {
	std::cout << BOLD_BRIGHT_RED_UNDERLINE << "mew" << RESET << std::endl;
}
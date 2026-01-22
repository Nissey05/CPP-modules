/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:15:56 by nhendrik          #+#    #+#             */
/*   Updated: 2026/01/22 19:56:08 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Animal::Animal() :
type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string name) :
type(name)
{
	std::cout << "Animal name constructor called" << std::endl;
}

Animal::Animal(const Animal& copy) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = copy;
}

Animal::~Animal() {
	std::cout << "Animal default destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& copy) {
	std::cout << "Animal copy assignment operator called" << std::endl;
	this->type = copy.type;
	return (*this);
}
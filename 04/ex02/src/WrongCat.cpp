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

#include "../inc/WrongCat.hpp"
#include <random>

WrongCat::WrongCat() :
WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string name) :
WrongAnimal(name)
{
	std::cout << "WrongCat name constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) :
WrongAnimal(copy)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = copy;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat default destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& copy) {
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	this->type = copy.type;
	return (*this);
}

void WrongCat::makeSound(void) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> e(2, 7), o(3, 10), dot(0, 5);


	std::cout << "M";
	int i = e(gen);
	while (i > 0)
	{
		std::cout << "e";
		i--;
	}
	i = o(gen);
	while (i > 0)
	{
		std::cout << "o";
		i--;
	}
	std::cout << "w";
	i = dot(gen);
	while (i > 0)
	{
		std::cout << ".";
		i--;
	}
	std::cout << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:19:50 by nhendrik          #+#    #+#             */
/*   Updated: 2026/01/21 20:45:07 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"
#include <random>

Cat::Cat() :
Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string name) :
Animal(name)
{
	std::cout << "Cat name constructor called" << std::endl;
}

Cat::Cat(const Cat& copy) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = copy;
}

Cat::~Cat() {
	std::cout << "Cat default destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& copy) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	this->type = copy.type;
	return (*this);
}

void Cat::makeSound(void) {
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
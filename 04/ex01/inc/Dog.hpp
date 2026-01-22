/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:19:19 by nhendrik          #+#    #+#             */
/*   Updated: 2026/01/22 14:40:42 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
	private:
		Brain *brain;
	public:
		Dog();
		Dog(std::string tpe);
		Dog(const Dog& copy);

		virtual ~Dog();
		virtual void makeSound();

		Dog& operator=(const Dog& copy);
};
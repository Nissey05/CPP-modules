/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:19:19 by nhendrik          #+#    #+#             */
/*   Updated: 2026/01/22 13:27:19 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include <iostream>
#include "Animal.hpp"

class Dog: public Animal {
	public:
		Dog();
		Dog(std::string tpe);
		Dog(const Dog& copy);

		virtual ~Dog();
		virtual void makeSound() const;

		Dog& operator=(const Dog& copy);
};
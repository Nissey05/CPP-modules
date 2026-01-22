/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:19:23 by nhendrik          #+#    #+#             */
/*   Updated: 2026/01/22 14:40:44 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal {
	private:
		Brain *brain;
	public:
		Cat();
		Cat(std::string type);
		Cat(const Cat& copy);

		virtual ~Cat();
		virtual void makeSound();

		Cat& operator=(const Cat& copy);
};
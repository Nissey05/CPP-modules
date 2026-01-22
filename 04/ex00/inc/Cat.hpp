/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:19:23 by nhendrik          #+#    #+#             */
/*   Updated: 2026/01/22 13:27:25 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <iostream>
#include "Animal.hpp"

class Cat: public Animal {
	public:
		Cat();
		Cat(std::string type);
		Cat(const Cat& copy);

		virtual ~Cat();
		virtual void makeSound();

		Cat& operator=(const Cat& copy);
};
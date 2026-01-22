/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:17:03 by nhendrik          #+#    #+#             */
/*   Updated: 2026/01/22 19:56:14 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal& copy);

		virtual ~Animal();

		Animal& operator=(const Animal& copy);

		virtual void makeSound() = 0;
};
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:19:19 by nhendrik          #+#    #+#             */
/*   Updated: 2026/02/16 22:07:53 by nhendrik         ###   ########.fr       */
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
		virtual void makeSound() const;

		Dog& operator=(const Dog& copy);

		void setIdea(int i, std::string idea);
		std::string getIdea(int i) const;
};
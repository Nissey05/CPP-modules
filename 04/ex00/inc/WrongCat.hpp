/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:19:23 by nhendrik          #+#    #+#             */
/*   Updated: 2026/01/22 13:29:51 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
	public:
		WrongCat();
		WrongCat(std::string type);
		WrongCat(const WrongCat& copy);

		virtual ~WrongCat();
		virtual void makeSound();

		WrongCat& operator=(const WrongCat& copy);
};
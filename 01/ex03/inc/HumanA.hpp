/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:39:00 by nhendrik          #+#    #+#             */
/*   Updated: 2025/11/23 19:53:50 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <Weapon.hpp>

class HumanA {
	private:
		std::string name;
		Weapon *weapon;
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
		void attack(void);
};

#endif
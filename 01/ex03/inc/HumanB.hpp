/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:49:42 by nhendrik          #+#    #+#             */
/*   Updated: 2025/11/23 19:52:21 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <Weapon.hpp>

class HumanB {
	private:
		std::string name;
		Weapon *weapon;
	public:
		HumanB(std::string name);
		~HumanB(void);
		void attack(void);
		void setWeapon(Weapon &weapon);
};

#endif
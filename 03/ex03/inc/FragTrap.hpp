/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:26:35 by nhendrik          #+#    #+#             */
/*   Updated: 2026/01/27 14:29:09 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap {
	protected:
		static const unsigned int init_val_hit_points = 100;
		static const unsigned int init_val_energy_points = 100;
		static const unsigned int init_val_attack_points = 30;
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& copy);

		virtual ~FragTrap();

		FragTrap& operator=(const FragTrap& copy);

		void highFivesGuys(void);
};

#endif
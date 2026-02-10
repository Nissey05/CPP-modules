/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 00:01:27 by nhendrik          #+#    #+#             */
/*   Updated: 2026/02/10 17:01:07 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
	private:
		bool guarding = false;
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& copy);

		~ScavTrap();

		ScavTrap& operator=(const ScavTrap& copy);

		void attack(const std::string& target);
		void guardGate(void);
};

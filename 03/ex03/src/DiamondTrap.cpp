/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:52:02 by nhendrik          #+#    #+#             */
/*   Updated: 2026/01/15 13:14:15 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout << "DiamondTrap default constructor called" << std::endl;
	name = "DiamondTrap";
	ClapTrap::name = "DiamondTrap_clap_name";
	hit_points = 100;
	energy_points = 50;
	attack_points = 20;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name){
	std::cout << "DiamondTrap name constructor called" << std::endl;
	this->name = name;
	ClapTrap::name.append("_clap_name");
	hit_points = 100;
	energy_points = 50;
	attack_points = 20;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy) {
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	ClapTrap::operator=(copy);
	return (*this);
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = copy;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap default destructor called" << std::endl;
}

void DiamondTrap::whoAmI(void) {
	std::cout << "My DiamondTrap name is " << this->name << ". My Claptrap name is " << ClapTrap::name << "." << std::endl;
}
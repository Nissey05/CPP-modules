/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:52:02 by nhendrik          #+#    #+#             */
/*   Updated: 2026/01/27 14:49:34 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout << "DiamondTrap default constructor called" << std::endl;
	name = "DiamondTrap";
	ClapTrap::name = "DiamondTrap_clap_name";
	hit_points = FragTrap::init_val_hit_points;
	energy_points = ScavTrap::init_val_energy_points;
	attack_points = FragTrap::init_val_attack_points;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name){
	std::cout << "DiamondTrap name constructor called" << std::endl;
	this->name = name;
	ClapTrap::name.append("_clap_name");
	hit_points = FragTrap::init_val_hit_points;
	energy_points = ScavTrap::init_val_energy_points;
	attack_points = FragTrap::init_val_attack_points;
	std::cout << hit_points << " " << energy_points << " " << attack_points << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy) {
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	ClapTrap::operator=(copy);
	return (*this);
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy){
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = copy;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap default destructor called" << std::endl;
}

void DiamondTrap::whoAmI(void) {
	std::cout << "My DiamondTrap name is " << this->name << ". My Claptrap name is " << ClapTrap::name << "." << std::endl;
	//std::cout << "I have " << attack_points << " attack_points, " << hit_points << " hit_points and " << energy_points << " energy_points." << std::endl; 
}
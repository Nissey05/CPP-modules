/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:26:39 by nhendrik          #+#    #+#             */
/*   Updated: 2026/01/27 14:29:38 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"


FragTrap::FragTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
	name = "FragTrap";
	hit_points = init_val_hit_points;
	energy_points = init_val_energy_points;
	attack_points = init_val_attack_points;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap name constructor called" << std::endl;
	hit_points = init_val_hit_points;
	energy_points = init_val_energy_points;
	attack_points = init_val_attack_points;
	this->name = name;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy) {
	std::cout << "FragTrap copy constructor called" << std::endl;}

FragTrap::~FragTrap() {
	std::cout << "FragTrap default destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& copy) {
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	ClapTrap::operator=(copy);
	return (*this);
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << name << " asks for a high-five." << std::endl;
}

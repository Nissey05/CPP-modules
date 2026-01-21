/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:26:39 by nhendrik          #+#    #+#             */
/*   Updated: 2026/01/19 16:02:19 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


FragTrap::FragTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
	name = "FragTrap";
	hit_points = 100;
	energy_points = 100;
	attack_points = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap name constructor called" << std::endl;
	hit_points = 100;
	energy_points = 100;
	attack_points = 30;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:26:39 by nhendrik          #+#    #+#             */
/*   Updated: 2026/02/10 18:44:54 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "colors.h"


FragTrap::FragTrap() {
	std::cout << BOLD_BRIGHT_MAGENTA << "FragTrap default constructor called" << RESET << std::endl;
	name = "FragTrap";
	hit_points = 100;
	energy_points = 100;
	attack_points = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << BOLD_BRIGHT_MAGENTA << "FragTrap name constructor called" << RESET << std::endl;
	hit_points = 100;
	energy_points = 100;
	attack_points = 30;
	this->name = name;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy) {
	std::cout << BOLD_BRIGHT_MAGENTA << "FragTrap copy constructor called" << RESET << std::endl;}

FragTrap::~FragTrap() {
	std::cout << BOLD_BRIGHT_MAGENTA << "FragTrap default destructor called" << RESET << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& copy) {
	std::cout << BOLD_BRIGHT_MAGENTA << "FragTrap copy assignment operator called" << RESET << std::endl;
	if (&copy == this)
		return (*this);
	ClapTrap::operator=(copy);
	return (*this);
}

void FragTrap::highFivesGuys(void) {
	std::cout << BOLD_BRIGHT_MAGENTA << "FragTrap " << name << " asks for a high-five." << RESET << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:26:39 by nhendrik          #+#    #+#             */
/*   Updated: 2026/02/11 01:36:48 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"
#include "colors.h"

FragTrap::FragTrap() :
ClapTrap()
{
	std::cout << BOLD_BRIGHT_MAGENTA << "FragTrap default constructor called" << RESET << std::endl;
	name = "FragTrap";
	hit_points = init_val_hit_points;
	energy_points = init_val_energy_points;
	attack_points = init_val_attack_points;
}

FragTrap::FragTrap(std::string name) :
ClapTrap(name)
{
	std::cout << BOLD_BRIGHT_MAGENTA << "FragTrap name constructor called" << RESET << std::endl;
	hit_points = init_val_hit_points;
	energy_points = init_val_energy_points;
	attack_points = init_val_attack_points;
	this->name = name;
}

FragTrap::FragTrap(const FragTrap& copy) :
ClapTrap(copy)
{
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

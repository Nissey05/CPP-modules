/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 00:15:07 by nhendrik          #+#    #+#             */
/*   Updated: 2026/02/10 18:38:03 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "colors.h"

ScavTrap::ScavTrap() {
	std::cout << BOLD_BRIGHT_YELLOW << "ScavTrap default constructor called" << RESET << std::endl;
	name = "ScavTrap";
	hit_points = 100;
	energy_points = 50;
	attack_points = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << BOLD_BRIGHT_YELLOW << "ScavTrap name constructor called" << RESET << std::endl;
	hit_points = 100;
	energy_points = 50;
	attack_points = 20;
	this->name = name;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy) {
	std::cout << BOLD_BRIGHT_YELLOW << "ScavTrap copy constructor called" << RESET << std::endl;}

ScavTrap::~ScavTrap() {
	std::cout << BOLD_BRIGHT_YELLOW << "ScavTrap default destructor called" << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy) {
	std::cout << BOLD_BRIGHT_YELLOW << "ScavTrap copy assignment operator called" << RESET << std::endl;
	if (&copy == this)
		return (*this);
	ClapTrap::operator=(copy);
	return (*this);
}

void ScavTrap::attack(const std::string& target) {
	if (!energy_points || !hit_points)
	{
		std::cout << BOLD_BRIGHT_YELLOW << "ScavTrap " << name << " has ran out of hit- &/or energy points!" << RESET << std::endl;
		return ;
	}
	std::cout << BOLD_BRIGHT_YELLOW << "ScavTrap " << name << " attacks " << target << ", causing " << attack_points << " points of damage!" << RESET << std::endl;
	energy_points--;
}

void ScavTrap::guardGate(void)
{
	std::cout << BOLD_BRIGHT_YELLOW << "ScavTrap " << name << " is now in Gate keeper mode." << RESET << std::endl;
}
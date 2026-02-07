/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 00:15:07 by nhendrik          #+#    #+#             */
/*   Updated: 2026/02/07 14:58:24 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


ScavTrap::ScavTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
	name = "ScavTrap";
	hit_points = 100;
	energy_points = 50;
	attack_points = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap name constructor called" << std::endl;
	hit_points = 100;
	energy_points = 50;
	attack_points = 20;
	this->name = name;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy) {
	std::cout << "ScavTrap copy constructor called" << std::endl;}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap default destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (&copy == this)
		return (*this);
	ClapTrap::operator=(copy);
	return (*this);
}

void ScavTrap::attack(const std::string& target) {
	if (!energy_points || !hit_points)
	{
		std::cout << "ScavTrap " << name << " has ran out of hit- &/or energy points!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attack_points << " points of damage!" << std::endl;
	energy_points--;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}
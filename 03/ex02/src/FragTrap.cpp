/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:26:39 by nhendrik          #+#    #+#             */
/*   Updated: 2026/01/15 12:36:37 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


FragTrap::FragTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
	name = "FragTrap";
	hit_points = 100;
	energy_points = 50;
	attack_points = 20;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap name constructor called" << std::endl;
	hit_points = 100;
	energy_points = 100;
	attack_points = 20;
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

void FragTrap::attack(const std::string& target) {
	if (!energy_points || !hit_points)
	{
		std::cout << "FragTrap " << name << " has ran out of hit- &/or energy points!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attack_points << " points of damage!" << std::endl;
	energy_points--;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << name << " asks for a high-five." << std::endl;
}

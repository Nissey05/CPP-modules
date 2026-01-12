/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:11:14 by nhendrik          #+#    #+#             */
/*   Updated: 2026/01/12 18:21:35 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap() {
	std::cout << "Default constructor called" << std::endl;
	name = "ClapTrap";
}

ClapTrap::ClapTrap(std::string name) {
	std::cout << "Name constructor called" << std::endl;
	this->name = name;
}

ClapTrap::ClapTrap(const ClapTrap& copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap() {
	std::cout << "Default destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->attack_points = copy.attack_points;
	this->energy_points = copy.energy_points;
	this->hit_points = copy.hit_points;
	this->name = copy.name;
	return (*this);
}

void ClapTrap::attack(const std::string& target) {
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_points << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << name << " has taken " << amount << " points of damage!" << std::endl;
	if (amount >= hit_points)
		hit_points = 0;
	else
		hit_points -= amount;
}
void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << name << " has repaired " << amount << " hitpoints!" << std::endl;
	hit_points += amount;
}
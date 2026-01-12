/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:11:14 by nhendrik          #+#    #+#             */
/*   Updated: 2026/01/13 00:00:45 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap() :
name("ClapTrap")
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :
name(name)
{
	std::cout << "Name constructor called" << std::endl;
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

static void print_error(unsigned int hit_points, unsigned int energy_points, std::string name)
{
	if (!hit_points && !energy_points)
	{
		std::cout << "ClapTrap " << name << " has ran out of hit- & energy points!" << std::endl;
		return ;
	}
	if (!hit_points)
	{
		std::cout << "ClapTrap " << name << " has ran out of hitpoints!" << std::endl;
		return ;
	}
	if (!energy_points)
	{
		std::cout << "ClapTrap " << name << " has ran out of energy points!" << std::endl;
		return ;
	}
}

void ClapTrap::attack(const std::string& target) {
	if (!energy_points || !hit_points)
	{
		print_error(hit_points, energy_points, name);
		return ;
	}
		
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_points << " points of damage!" << std::endl;
	energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (!hit_points)
	{
		print_error(hit_points, 1, name);
		return ;
	}
	std::cout << "ClapTrap " << name << " has taken " << amount << " points of damage!" << std::endl;
	if (amount >= hit_points)
		hit_points = 0;
	else
		hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (!hit_points || !energy_points)
	{
		print_error(hit_points, energy_points, name);
		return ;
	}
	std::cout << "ClapTrap " << name << " has repaired " << amount << " hitpoints!" << std::endl;
	hit_points += amount;
	energy_points--;
}
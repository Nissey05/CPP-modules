/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:29:32 by nhendrik          #+#    #+#             */
/*   Updated: 2025/12/28 21:26:06 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void) {
	std::cout << "Something is broken somewhere, go fix it." << std::endl;
}
void Harl::info(void) {
	std::cout << "Harl is Harl." << std::endl;
}
void Harl::warning(void) {
	std::cout << "Harl is breaking soon..." << std::endl;
}
void Harl::error(void) {
	std::cout << "Error: expected ';' after expression" << std::endl;
}

int get_level(std::string level)
{
	if (level == "DEBUG")
		return (0);
	if (level == "INFO")
		return (1);
	if (level == "WARNING")
		return (2);
	if (level == "ERROR")
		return (3);
	return (4);
}

void Harl::complain(std::string level) {
	void (Harl::*funcs[5])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error, nullptr};
	int levels = get_level(level);
	switch (levels)
	{
		case 0:
			(this->*funcs[0])();
        	[[fallthrough]];
		case 1:
			(this->*funcs[1])();
       		[[fallthrough]];
		case 2:
			(this->*funcs[2])();
        	[[fallthrough]];
		case 3:
			(this->*funcs[3])();
			break;
		default:
			std::cout << "Probably complaining about Pineapple on Pizza." << std::endl;
			break;
	}
}
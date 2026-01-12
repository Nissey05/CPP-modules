/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:29:32 by nhendrik          #+#    #+#             */
/*   Updated: 2026/01/12 16:32:02 by nhendrik         ###   ########.fr       */
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

void Harl::complain(std::string level) {
	void (Harl::*funcs[5])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error, nullptr};
	std::string levels[5] = {"DEBUG", "INFO", "WARNING", "ERROR", nullptr};
	int i = 0;
	while (i < 4 && levels[i] != level)
		i++;
	if (funcs[i] != nullptr)
		(this->*funcs[i])();
}
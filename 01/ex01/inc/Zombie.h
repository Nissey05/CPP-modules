/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 17:20:41 by nhendrik          #+#    #+#             */
/*   Updated: 2026/02/04 18:09:11 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_H
# define ZOMBIE_H

# define BOLD_RED "\033[1;7;31m"
# define GREEN "\033[1;4;32m"
# define RESET "\033[0m"

#include <iostream>
#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

#endif
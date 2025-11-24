/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 17:20:41 by nhendrik          #+#    #+#             */
/*   Updated: 2025/11/23 17:22:01 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include "Zombie.hpp"

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

#endif
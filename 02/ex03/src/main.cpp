/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:55:23 by nhendrik          #+#    #+#             */
/*   Updated: 2026/01/28 20:19:42 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	Point a(-100, -100);
	Point b(100, 0);
	Point c(-45, 150);
	Point point(-50.f, -50.f);
	Point pointa(50.f, 50.f);
	Point pointb(50.f, 100.f);
	if (bsp(a, b, c, point))
		std::cout << "its inside 1!" << std::endl;
	if (bsp(a, b, c, pointa))
		std::cout << "its inside 2!" << std::endl;
	if (bsp(a, b, c, pointb))
		std::cout << "its inside 3!" << std::endl;
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:55:23 by nhendrik          #+#    #+#             */
/*   Updated: 2026/02/10 16:03:37 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	
	std::cout << "-------------------------------My tests----------------------------" << std::endl;
	Fixed c(5);
	Fixed d(7);
	std::cout << "c + d: " << c + d << std::endl;
	std::cout << "c - d: " << c - d << std::endl;
	std::cout << "max(c, d): " << Fixed::max(c, d) << std::endl;
	std::cout << "--d: " << --d << std::endl;
	std::cout << "d--: " << d-- << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "max(++c, d--): " << Fixed::max(++c, d--) << std::endl;
	std::cout << "min(c, d): " << Fixed::min(c, d) << std::endl;
	std::cout << "c: " << c << ", d: " << d << std::endl;
	if (c == d)
		std::cout << "c == d" << std::endl;
	if (c != d)
		std::cout << "c != d" << std::endl;
	if (c <= d)
		std::cout << "c <= d" << std::endl;
	if (c >= d)
		std::cout << "c >= d" << std::endl;
	if (c < d)
		std::cout << "c < d" << std::endl;
	if (c > d)
		std::cout << "c > d" << std::endl;
	c = 5;
	d = 5;
	std::cout << "c: " << c << ", d: " << d << std::endl;
	if (c == d)
		std::cout << "c == d" << std::endl;
	if (c != d)
		std::cout << "c != d" << std::endl;
	if (c <= d)
		std::cout << "c <= d" << std::endl;
	if (c >= d)
		std::cout << "c >= d" << std::endl;
	if (c < d)
		std::cout << "c < d" << std::endl;
	if (c > d)
		std::cout << "c > d" << std::endl;
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:29:32 by nhendrik          #+#    #+#             */
/*   Updated: 2026/02/05 15:53:02 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::fractional_bits = 8;

Fixed::Fixed()
{
	//std::cout << "Default constructor called" << std::endl;
	value = 0;
}


Fixed::Fixed(const int val) {
	value = val << fractional_bits;
}

Fixed::Fixed(const float val) {
	value = (int)roundf(val * (1 << fractional_bits));
}

Fixed::Fixed(const Fixed& copy) {
	//std::cout << "Copy constructor called" << std::endl;
	this->value = copy.value;
}

Fixed::~Fixed() {
	//std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) {
	//std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void Fixed::setRawBits(int const raw) {
	//std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

Fixed& Fixed::operator=(const Fixed& copy) {
	//std::cout << "Copy assignment operator called" << std::endl;
	this->value = copy.value;
	return (*this);
}


float Fixed::toFloat(void) const {
	return (static_cast<float>((float)value / (float)(1 << fractional_bits)));
}

int Fixed::toInt(void) const {
	return ((int)value >> fractional_bits);
}

bool Fixed::operator>(const Fixed& other) const {
	return (value > other.value ? true : false);
}

bool Fixed::operator<(const Fixed& other) const {
	return (value < other.value ? true : false);
}

bool Fixed::operator>=(const Fixed& other) const {
	return (value >= other.value ? true : false);
	
}

bool Fixed::operator<=(const Fixed& other) const {
	return (value <= other.value ? true : false);
}

bool Fixed::operator==(const Fixed& other) const {
	return (value == other.value ? true : false);
}

Fixed Fixed::operator+(const Fixed& other) const {
	return (toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
	return (toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
	return (this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
	return (this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
	value++;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	++value;
	return (temp);
}

Fixed& Fixed::operator--() {
	value--;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	--value;
	return (temp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a < b ? b : a);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a < b ? b : a);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}

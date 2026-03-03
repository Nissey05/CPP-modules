#include "ScalarConverter.hpp"

#include <iostream>

void printChar(std::string input)
{
	
	char c;
	if (c > 127 || c < 0)
		return ;
	std::cout << c << std::endl;
}

void printInt(std::string input)
{
	int nb = std::stoi(input);
	std::cout << nb << std::endl;
}

void ScalarConverter::convert(std::string input) {
	printChar(input);
	printInt(input);
}
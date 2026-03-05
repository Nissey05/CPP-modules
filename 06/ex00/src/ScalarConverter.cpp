#include "ScalarConverter.hpp"

#include <iostream>
#include <iomanip>

void printChar(std::string &input)
{
	int c;
	if (input[1])
		c = std::stoi(input);
	else
		c = (int)input.c_str()[0];
	if (c > 127 || c < 0)
		return ;
	std::cout << "char: ";
	if (c < '!' || c == 127)
		std::cout << "Not displayable" << std::endl;
	else
		std::cout << (char)c << std::endl;
	std::cout << "int: " << c << std::endl;
	std::cout << std::setprecision(1) << std::fixed;
	std::cout << "float: " << static_cast<float>(c) << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void printInt(std::string &input)
{
	int nb = std::stoi(input);
	std::cout << "int: ";
	std::cout << nb << std::endl;
}

void printFloat(std::string &input)
{
	float fl = std::stof(input);
	std::cout << std::setprecision(1) << std::fixed;
	std::cout << "float: ";
	std::cout << fl << 'f' << std::endl;
}

void printDouble(std::string &input)
{
	double dbl = std::stod(input);
	std::cout << "double: ";
	std::cout << dbl << std::endl;
}

Types getType(std::string &input)
{
	(void)input;
	return (Char);
}

void ScalarConverter::convert(std::string input) {
	Types type = getType(input);
	switch (type)
	{
		case Char:
			printChar(input);
			break;
		case Int:
			printInt(input);
			break;
		case Float:
			printFloat(input);
			break;
		case Double:
			printDouble(input);
			break;
		default:
			return;
	}
}
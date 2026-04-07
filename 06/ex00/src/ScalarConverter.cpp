#include "ScalarConverter.hpp"

#include <iostream>
#include <iomanip>
#include <cmath>

void printChar(std::string &input)
{
	char c = input.c_str()[1];
	std::cout << "char: ";
	if (c < '!' || c == 127)
		std::cout << "Not displayable" << std::endl;
	else
		std::cout << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::setprecision(1) << std::fixed;
	std::cout << "float: " << static_cast<float>(c) << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void printInt(std::string &input)
{
	int nb = std::stoi(input);
	std::cout << "char: ";
	if (nb >= 128)
		std::cout << "impossible" << std::endl;
	else if (nb < '!' || nb == 127)
		std::cout << "Not displayable" << std::endl;
	else
		std::cout << static_cast<char>(nb) << std::endl;
	std::cout << "int: " << nb << std::endl;
	std::cout << std::setprecision(1) << std::fixed;
	std::cout << "float: " << static_cast<float>(nb) << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(nb) << std::endl;
}

void printFloat(std::string &input)
{
	float fl = std::stof(input);
	std::cout << "char: ";
	if (!std::isfinite(fl) || fl >= 128)
		std::cout << "impossible" << std::endl;
	else if (fl < '!' || fl == 127)
		std::cout << "Not displayable" << std::endl;
	else
		std::cout << static_cast<char>(fl) << std::endl;
	std::cout << "int: ";
	if (fl <= INT_MAX_FLOAT && fl >= INT_MIN_FLOAT && std::isfinite(fl))
		std::cout << static_cast<int>(fl) << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << std::setprecision(1) << std::fixed;
	std::cout << "float: " << fl << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(fl) << std::endl;
}

void printDouble(std::string &input)
{
	double dbl = std::stod(input);
	std::cout << "char: ";
	if (!std::isfinite(dbl) || dbl >= 128)
		std::cout << "impossible" << std::endl;
	else if (dbl < '!' || dbl >= 127)
		std::cout << "Not displayable" << std::endl;
	else
		std::cout << static_cast<char>(dbl) << std::endl;
	std::cout << "int: ";
	if (dbl <= INT_MAX_FLOAT && dbl >= INT_MIN_FLOAT && std::isfinite(dbl))
		std::cout << static_cast<int>(dbl) << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << std::setprecision(1) << std::fixed;
	std::cout << "float: " << static_cast<float>(dbl) << 'f' << std::endl;
	std::cout << "double: " << dbl << std::endl;
}

bool isEncased(std::string &input, char c)
{
	if (input[0] == c && *(--input.end()) == c)
		return (true);
	return (false);
}

bool isInt(std::string &input)
{
	int nb;
	try
	{
		nb = std::stoi(input);
		return (true);
	}
	catch(const std::exception& e)
	{
		return (false);
	}
}

bool checkFinites(std::string &input)
{
	std::string nonfinites[3] = {"+inf", "-inf", "nan"};
	for (int i = 0; i < 3; i++)
	{
		size_t ret = input.find(nonfinites[i]);
		if (ret != input.npos && !ret)
		{
			if (i == 2 && ((input[3] == 'f' && input.length() == 4) || input.length() == 3))
				return (true);
			else if (i < 2 && ((input[4] == 'f' && input.length() == 5) || input.length() == 4))
				return (true);
		}
	}
	return (false);
};

bool isDouble(std::string &input)
{
	size_t pos = input.find(".");
	if (!checkFinites(input))
	{
		if (pos == input.npos)
			return (false);
		if (input.find(".", pos + 1) != input.npos)
			return (false);
	}
	return (true);
}

bool isFloat(std::string &input)
{
	size_t pos = input.find(".");
	if (!checkFinites(input))
	{
		if (pos == input.npos)
			return (false);
		if (input.find(".", pos + 1) != input.npos)
			return (false);
	}
	if (*(--input.end()) != 'f')
		return (false);
	return (true);
	
}

bool isChar(std::string &input)
{
	if (input.size() == 3 && isEncased(input, '\''))
		return (true);
	return (false);
}

Types getType(std::string &input)
{
	if (isChar(input))
		return (Char);
	if (isFloat(input))
		return (Float);
	if (isDouble(input))
		return (Double);
	if (isInt(input))
		return (Int);
	return (None);
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
			std::cerr << "Invalid input" << std::endl;
			return;
	}
}
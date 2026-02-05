#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

int main(void)
{
	try
	{
		Bureaucrat pieter("Pieter", 200);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "Excepsussy" << std::endl; 
	}
}
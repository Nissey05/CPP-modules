#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

int main(void)
{
	try
	{
		Bureaucrat pieter("Pieter", 200);
		std::cout << pieter << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl; 
	}

	try
	{
		Bureaucrat barteld("Barteld", 0);
		std::cout << barteld << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl; 
	}

	try
	{
		Bureaucrat teun("Teun", 1);
		std::cout << teun << std::endl;
		teun.incrementGrade();
		std::cout << teun << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat klaas("Klaas", 50);
		std::cout << klaas << std::endl;
		klaas.incrementGrade();
		std::cout << klaas << std::endl;
		for (int i = 0; i < 50; i++)
			klaas.decrementGrade();
		std::cout << klaas << std::endl;
		for (int i = 0; i < 51; i++)
			klaas.decrementGrade();
		std::cout << klaas << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <stdexcept>

int main(void)
{
	try
	{
		Bureaucrat	bikkel("Bikkel", 25);
		Bureaucrat	johannes("Johannes", 45);
		AForm *form = new PresidentialPardonForm("Obama");
		bikkel.signForm(*form);
		form->execute(bikkel);
		johannes.signForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{

		Bureaucrat	reau("Reau", 1);
		AForm *form = new RobotomyRequestForm("Obama");
		form->execute(reau);
		reau.signForm(*form);
		form->execute(reau);
		form->execute(reau);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat	shrub("Shrub", 1);
		AForm *form = new ShrubberyCreationForm("Shrubster");
		shrub.signForm(*form);
		form->execute(shrub);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <stdexcept>

int main(void)
{
	AForm *form = nullptr;
	try
	{
		Intern robert;
		form = robert.makeForm("presidential pardon", "Obama");
		Bureaucrat zephod("Zephod", 7);

		zephod.signForm(*form);
		form->execute(zephod);

		zephod.incrementGrade();
		zephod.incrementGrade();
		zephod.executeForm(*form);
		std::cout << zephod << std::endl;

		std::cout << "Increment loop: " << std::endl;
		for (int i = 0; i < 10; i++)
			zephod.incrementGrade();
		std::cout << zephod << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	if (form)
		delete form;
	form = nullptr;
	try
	{
		Intern petra;
		form = petra.makeForm("Pizza form", "Peperoni");
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	if (form)
		delete form;
}
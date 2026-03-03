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
	try
	{
		Intern robert;
		AForm *president = robert.makeForm("presidential pardon", "Obama");
		Bureaucrat zephod("Zephod", 1);
		zephod.signForm(*president);
		president->execute(zephod);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
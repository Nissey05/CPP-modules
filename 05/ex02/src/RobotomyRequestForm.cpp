#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "RNG.h"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() :
AForm("RobotomyRequestForm", 45, 72),
target("R.O.B.")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
AForm("RobotomyRequestForm", 45, 72),
target(target)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) :
AForm("RobotomyRequestForm", 45, 72)
{
	*this = copy;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		target = copy.target;
	}
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (!getSign())
			throw UnsignedForm();
		if (executor.getGrade() > getExecGrade())
			throw GradeTooHighException();
		int nmb = RNG(0, 1);
		if (nmb)
			std::cout << "Bzzzrt " << target << " robotomized succesfully" << std::endl;
		else
			std::cout << "Bzzzz robotomization of " << target << " failed." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << executor.getName() << " couldn't execute the " << getName() << " because " << e.what() << '\n';
	}
	
}
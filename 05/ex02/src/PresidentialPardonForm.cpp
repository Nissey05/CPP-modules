#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() :
AForm("PresidentialPardonForm", 5, 25),
target("Arthur Dent")
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &str) :

{

}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm default destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) :
AForm(copy.getName(), 5, 25)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = copy;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		AForm::operator=(copy);
		return (*this);
	}
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (executor.getGrade() > getExecGrade())
			throw GradeTooHighException();
		std::cout << "Informs that" << target << "has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

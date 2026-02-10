#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm() :
name(""), sign_grade(150), exec_grade(150)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, const int exec_grade, const int sign_grade) :
name(name), sign_grade(sign_grade), exec_grade(exec_grade)
{
	if (exec_grade > 150)
		throw GradeTooHighException();
	if (exec_grade <= 0)
		throw GradeTooLowException();
	if (sign_grade > 150)
		throw GradeTooHighException();
	if (sign_grade <= 0)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& copy) :
name(copy.name), sign_grade(copy.sign_grade), exec_grade(copy.exec_grade)
{
	std::cout << "AForm copy constructor called" << std::endl;
	if (exec_grade > 150)
		throw GradeTooHighException();
	if (exec_grade <= 0)
		throw GradeTooLowException();
	if (sign_grade > 150)
		throw GradeTooHighException();
	if (sign_grade <= 0)
		throw GradeTooLowException();
	if (this != &copy)
	{
		*this = copy;
	}
}

AForm&	AForm::operator=(const AForm& copy)
{
	std::cout << "AForm copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		sign = copy.sign;
	}
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm default destructor called" << std::endl;
}

const std::string &AForm::getName() const
{
	return (name);
}

bool AForm::getSign() const
{
	return (sign);
}

int AForm::getSignGrade() const
{
	return (sign_grade);
}

int AForm::getExecGrade() const
{
	return (exec_grade);
}

void AForm::beSigned(const Bureaucrat& bc)
{
	if (bc.getGrade() > sign_grade)
		throw GradeTooLowException();
	sign = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too high");
}


std::ostream& operator<<(std::ostream &os, const AForm &Aform)
{
	os << Aform.getName() << ", Aform has sign: " << Aform.getSign() << ", sign grade: " << Aform.getSignGrade() << " & exec grade: " << Aform.getExecGrade() << std::endl;
	return (os);
}
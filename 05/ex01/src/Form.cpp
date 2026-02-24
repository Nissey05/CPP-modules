#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form() :
name(""), sign_grade(150), exec_grade(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name, const int exec_grade, const int sign_grade) :
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

Form::Form(const Form& copy) :
name(copy.name), sign_grade(copy.sign_grade), exec_grade(copy.exec_grade)
{
	std::cout << "Form copy constructor called" << std::endl;
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

Form&	Form::operator=(const Form& copy)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		sign = copy.sign;
	}
	return (*this);
}

Form::~Form()
{
	std::cout << "Form default destructor called" << std::endl;
}

const std::string &Form::getName() const
{
	return (name);
}

bool Form::getSign() const
{
	return (sign);
}

int Form::getSignGrade() const
{
	return (sign_grade);
}

int Form::getExecGrade() const
{
	return (exec_grade);
}

void Form::beSigned(const Bureaucrat& bc)
{
	if (bc.getGrade() > sign_grade)
		throw GradeTooLowException();
	sign = true;
}

const char *Form::GradeTooHighException::what() const noexcept
{
	return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const noexcept
{
	return ("Grade is too high");
}


std::ostream& operator<<(std::ostream &os, const Form &form)
{
	os << form.getName() << ", form has sign: " << form.getSign() << ", sign grade: " << form.getSignGrade() << " & exec grade: " << form.getExecGrade() << std::endl;
	return (os);
}
#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

Bureaucrat::Bureaucrat()
: name("Bureaucrat"), grade(150)
{}


Bureaucrat::Bureaucrat(const std::string &name, int grade)
: name(name)
{
	if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException;
		return;
	}
	if (grade < 0)
	{
		throw Bureaucrat::GradeTooHighException;
		return;
	}
	this->grade = grade;
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat::Bureaucrat(const Bureaucrat& cpy)
: name(cpy.name)
{
	if (this != &cpy)
	{
		*this = cpy;
	}
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& cpy)
{
	if (this != &cpy)
	{
		this->grade = cpy.grade;
	}
	return (*this);
}

void Bureaucrat::incrementGrade(void) {
	if (grade - 1 > 150)
	{
		throw Bureaucrat::GradeTooLowException;
		return;
	}
	if (grade - 1 < 0)
	{
		throw Bureaucrat::GradeTooHighException;
		return;
	}
	grade--;
}

void Bureaucrat::decrementGrade(void) {
	if (grade - 1 > 150)
	{
		throw Bureaucrat::GradeTooLowException;
		return;
	}
	if (grade - 1 < 0)
	{
		throw Bureaucrat::GradeTooHighException;
		return;
	}
	grade++;
}

const std::string& Bureaucrat::getName(void) const {
	return (this->name);
}

int Bureaucrat::getGrade(void) const {
	return (grade);
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &bc) {
	os << bc.getGrade();
	return (os);
}

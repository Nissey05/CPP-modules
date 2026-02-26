#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <stdexcept>

Bureaucrat::Bureaucrat()
: name("Bureaucrat"), grade(150)
{}


Bureaucrat::Bureaucrat(const std::string &name, int grade)
: name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade <= 0)
		throw Bureaucrat::GradeTooHighException();
	this->grade = grade;
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat::Bureaucrat(const Bureaucrat& cpy)
: name(cpy.name)
{
	*this = cpy;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& cpy)
{
	if (this != &cpy)
	{
		this->grade = cpy.grade;
	}
	return (*this);
}

const char *Bureaucrat::GradeTooHighException::what(void) const noexcept
{
	return ("The bureaucrats grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what(void) const noexcept
{
	return ("The bureaucrats grade is too low");
}

void Bureaucrat::incrementGrade(void) {
	if (grade - 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade - 1 <= 0)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade(void) {
	if (grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade + 1 <= 0)
		throw Bureaucrat::GradeTooHighException();
	grade++;
}

const std::string& Bureaucrat::getName(void) const {
	return (this->name);
}

int Bureaucrat::getGrade(void) const {
	return (grade);
}

void Bureaucrat::signForm(AForm& form) const {
	try
	{
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
	
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &bc) {
	os << bc.getName() << ", bureaucrat grade " << bc.getGrade();
	return (os);
}

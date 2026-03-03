#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {
	// std::cout << "Intern default constructor called" << std::endl;
};

Intern::~Intern() {
	// std::cout << "Intern default destructor called" << std::endl;
};

Intern::Intern(const Intern& cpy) {
	*this = cpy;
}

Intern&	Intern::operator=(const Intern& cpy) {
	if (this != &cpy)
	{
		return (*this);
	}
	return (*this);
}

AForm *Intern::makeForm(const std::string &form_name, const std::string &target) const {
	const std::string forms[3] = {{"presidential pardon"}, {"robotomy request"}, {"shrubbery creation"}};
	int i = 0;
	while (i < 3 && forms[i] != form_name)
		i++;
	AForm *form = nullptr;
	switch (i)
	{
		case (PresidentialPardon):
			form = new PresidentialPardonForm(target);
			break;
		case (RobotomyRequest):
			form = new RobotomyRequestForm(target);
			break;
		case (ShrubberyCreation):
			form = new ShrubberyCreationForm(target);
			break;
		default:
			throw InvalidFormException();
	}
	if (form)
		std::cout << "Intern creates " << form->getName() << std::endl;
	return (form);
}

const char *Intern::InvalidFormException::what() const noexcept {
	return ("Invalid form");
}
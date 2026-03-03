#pragma once

#include <string>
#include "AForm.hpp"

enum Forms {
	PresidentialPardon,
	RobotomyRequest,
	ShrubberyCreation
};

class	Intern
{
	public:
		Intern();
		Intern(const Intern& copy);
		~Intern();

		Intern&	operator=(const Intern& copy);
		AForm *makeForm(const std::string &form_name, const std::string &target) const;

		class InvalidFormException : public std::exception
		{
			public:
				virtual const char *what() const noexcept override;
		};
};
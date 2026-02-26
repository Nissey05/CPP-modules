#pragma once

#include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{
	private:
		std::string target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		~PresidentialPardonForm();

		PresidentialPardonForm&	operator=(const PresidentialPardonForm& copy);

		// void beSigned(const Bureaucrat &bc);
		void execute(Bureaucrat const & executor) const;
};
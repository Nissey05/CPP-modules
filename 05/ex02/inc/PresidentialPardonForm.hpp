#pragma once

#include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		~PresidentialPardonForm();

		PresidentialPardonForm&	operator=(const PresidentialPardonForm& copy);

		// void beSigned(const Bureaucrat &bc);
		void execute(Bureaucrat const & executor) const;

};
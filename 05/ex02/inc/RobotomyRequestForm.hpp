#pragma once

#include <string>
#include "AForm.hpp"

class	RobotomyRequestForm : public AForm
{
	private:
		std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		~RobotomyRequestForm();

		RobotomyRequestForm&	operator=(const RobotomyRequestForm& copy);

		void execute(Bureaucrat const & executor) const;
};
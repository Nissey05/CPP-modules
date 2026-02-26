#pragma once

#include <string>
#include "AForm.hpp"

class	ShrubberyCreationForm : public AForm
{
	private:
		std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		~ShrubberyCreationForm();

		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& copy);

		void execute(Bureaucrat const & executor) const;

		class FailedToOpenFile : public std::exception
		{
			virtual const char *what() const noexcept;
		};
};
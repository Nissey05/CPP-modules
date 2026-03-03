#pragma once
#include <iostream>

class AForm;

class	Bureaucrat
{
	private:
		const std::string name;
		int	grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& cpy);
		Bureaucrat&	operator=(const Bureaucrat& cpy);

		void incrementGrade(void);
		void decrementGrade(void);
		const std::string& getName(void) const;
		int getGrade(void) const;

		void signForm(AForm& form) const;
		void executeForm(AForm const &form) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const noexcept override;
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const noexcept override;
		};

};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &bc);
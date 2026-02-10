#pragma once
#include <iostream>

class Form;

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

		void signForm(Form& form) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &bc);
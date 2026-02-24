#pragma once

#include <iostream>

class Bureaucrat;

class	Form
{
	private:
		const		std::string name;
		bool		sign = false;
		const int	sign_grade;
		const int	exec_grade;
	public:
		Form();
		Form(const std::string& name, const int exec_grade, const int sign_grade);
		Form(const Form& copy);
		~Form();

		Form&	operator=(const Form& copy);

		const std::string &getName() const;
		bool getSign() const;
		int getSignGrade() const;
		int getExecGrade() const;

		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const noexcept;
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const noexcept;
		};

		void beSigned(const Bureaucrat& bc);

};

std::ostream& operator<<(std::ostream &os, const Form &form);

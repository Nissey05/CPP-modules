#pragma once
#include <iostream>

class Exception : public std::exception
{
	private:
		std::string err;

	public:
		Exception(const std::string &str) : err(str) {}
		virtual const char *what() const noexcept override { return err.c_str(); }
};

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
		Exception GradeTooHighException;
		Exception GradeTooLowException;

};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &bc);
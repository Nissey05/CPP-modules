#pragma once

#include <iostream>

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	bool sign = false;
	const int sign_grade;
	const int exec_grade;

public:
	AForm();
	AForm(const std::string& name, const int exec_grade, const int sign_grade);
	AForm(const AForm& copy);
	~AForm();

	AForm &operator=(const AForm &copy);

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

	class UnsignedForm : public std::exception
	{
		public:
			virtual const char *what() const noexcept;
	};
	virtual void beSigned(const Bureaucrat &bc);
	virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &Aform);

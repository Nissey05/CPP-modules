#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() :
AForm("ShrubberyCreationForm", 137, 145),
target("Shrub")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
AForm("ShrubberyCreationForm", 137, 145),
target(target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
{
	*this = copy;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		target = copy.target;
	}
	return (*this);
}

const char *ShrubberyCreationForm::FailedToOpenFile::what() const noexcept
{
	return ("Failed to open file");
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (!getSign())
			throw UnsignedForm();
		if (executor.getGrade() > getExecGrade())
			throw GradeTooHighException();
		std::ofstream fs(target + "_shrubbery");
		if (!fs)
			throw FailedToOpenFile();
		fs << "           *" << std::endl;
		fs << "          / \\" << std::endl;
		fs << "         /   \\" << std::endl;
		fs << "        / o   \\" << std::endl;
		fs << "         /   \\" << std::endl;
		fs << "        /o    \\" << std::endl;
		fs << "       /    o  \\" << std::endl;
		fs << "        /     \\" << std::endl;
		fs << "       /  o    \\" << std::endl;
		fs << "      / o       \\" << std::endl;
		fs << "     /        o  \\" << std::endl;
		fs << "    /  o   o      \\" << std::endl;
		fs << "   /^^^^^|^^^|^^^^^\\" << std::endl;
		fs << "         |   |" << std::endl;
		fs << "         |   |" << std::endl;
		fs << "         |___|" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << executor.getName() << " couldn't execute the " << getName() << " because " << e.what() << '\n';
	}
	
}
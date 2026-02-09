#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <stdexcept>

int main(void)
{
	try
	{
		Bureaucrat	bikkel("Bikkel", 25);
		Bureaucrat	johannes("Johannes", 45);
		Form		form("Food form", 30, 40);
		bikkel.signForm(form);
		johannes.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <stdexcept>

int main(void)
{
	try
	{
		Bureaucrat	bikkel("Bikkel", 25);
		Bureaucrat	johannes("Johannes", 45);
		bikkel.signForm(form);
		johannes.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
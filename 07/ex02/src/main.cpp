#include <iostream>
#include "Array.hpp"

int main(void)
{
	Array<int> a(5);
	std::cout << a[0] << std::endl;
	a[0] = 5;
	std::cout << a[0] << std::endl;
	try
	{
		a[5];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
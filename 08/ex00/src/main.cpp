#include "easyfind.hpp"
#include <iostream>

int main(void)
{
	std::vector<int> v = {5, 4, 3, 6, 2};
	try
	{
		easyfind(v, 4);
		std::cout << "easyfind 1 passed" << std::endl;
		easyfind(v, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
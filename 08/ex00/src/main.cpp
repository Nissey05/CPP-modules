#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main(void)
{
	std::vector<int> v = {5, 4, 3, 6, 2};
	auto it = easyfind(v, 4);
	if (it != v.end())
		std::cout << "easyfind 1 passed" << std::endl;
	else
		std::cout << "easyfind 1 failed" << std::endl;
	it = easyfind(v, 1);
	if (it != v.end())
		std::cout << "easyfind 2 passed" << std::endl;
	else
		std::cout << "easyfind 2 failed" << std::endl;
	
}
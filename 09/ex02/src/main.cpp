#include "PmergeMe.hpp"
#include <iostream>
#include <deque>
#include <vector>

template <typename Container>
static void fillContainer(Container &c, char **argv, int argc)
{
	for (int i = 1; i < argc; i++)
	{
		size_t nb = std::stol(argv[i]);
		c.push_back(nb);
	}
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j]; j++)
		{
			if (!isdigit(argv[i][j]))
			{
				std::cerr << "Error" << std::endl;
				return (1);
			}
		}
	}
	std::deque<size_t> d;
	std::vector<size_t> v;
	try
	{
		fillContainer(d, argv, argc);
		fillContainer(v, argv, argc);
	}
	catch(...)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	
	for (auto i : v)
	{
		std::cout << i << std::endl;
	}
}
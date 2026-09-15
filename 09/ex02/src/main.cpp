#include "PmergeMe.hpp"
#include <iostream>
#include <deque>
#include <vector>
#include <chrono>

template <typename Container>
static void fillContainer(Container &c, char **argv, int argc)
{
	for (int i = 1; i < argc; i++)
	{
		size_t nb = std::stol(argv[i]);
		c.push_back(nb);
	}
}

template <typename Container>
static void isSorted(Container &c)
{
	for (size_t i = 0; i + 1 < c.size(); i++)
	{
		if (c[i] > c[i + 1])
		{
			std::cout << "Incorrectly sorted: " << c[i] << " (" << i << ") " << " & " << c[i + 1] << " (" << i + 1 << ")" << std::endl;
			return ;
		}
	}
	std::cout << "Sorted correctly!\n";
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
	std::cout << "-- input: --" << std::endl;
	for (auto a : v)
		std::cout << a << " ";
	std::cout << std::endl;
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
	sortVec(v);
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	double us = std::chrono::duration<double, std::micro>(end - start).count();
	std::cout << "-- output: --" << std::endl;
	for (auto a : v)
		std::cout << a << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << v.size() << " elements with std::vector : " << us << " us" << std::endl;
	isSorted(v);
	start = std::chrono::steady_clock::now();
	sortDeque(d);
	end = std::chrono::steady_clock::now();
	us = std::chrono::duration<double, std::micro>(end - start).count();
	std::cout << "-- output: --" << std::endl;
	for (auto a : d)
		std::cout << a << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << d.size() << " elements with std::deque : " << us << " us" << std::endl;
	isSorted(d);
}
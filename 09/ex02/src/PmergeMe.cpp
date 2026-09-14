#include "PmergeMe.hpp"
#include <vector>
#include <iostream>

size_t getJacobsthalNumber(size_t number)
{
	size_t one = 0;
	size_t two = 1;
	size_t out = 0;
	while (number-- > 0)
	{
		out = two + 2 * one;
		one = two;
		two = out;
	}
	return (out);
}

void split_elements(std::vector<size_t> &vec,
	std::vector<std::pair<size_t, size_t>> &pairs)
{
	if (vec.size() <= 1)
		return ;
	for (size_t i = 0; i < vec.size() && vec.size() - i != 1; i+= 2)
	{
		if (vec[i] < vec[i + 1])
			pairs.push_back(std::pair<size_t, size_t>(vec[i + 1], vec[i]));
		else
			pairs.push_back(std::pair<size_t, size_t>(vec[i], vec[i + 1]));
	}
}

void realignPairs(std::vector<std::pair<size_t, size_t>> &pairs, std::vector<size_t> next)
{
	for (size_t i = 0; i < next.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (next[i] == pairs[j].first)
			{
				std::swap(pairs[i], pairs[j]);
				break ;
			}
		}
	}
}


void sortVec(std::vector<size_t> &vec)
{
	if (vec.size() <= 1)
		return ;
	std::vector<std::pair<size_t, size_t>> pairs;
	// 4 2 5 6 9 1
	split_elements(vec, pairs);
	std::vector <size_t> next;
	for (auto a : pairs)
	{
		next.push_back(a.first);
		std::cout << a.first << " " << a.second << std::endl;
	}
	// 4 2
	// 6 5
	// 9 1

	sortVec(next);
	realignPairs(pairs, next);
	next.insert(next.begin(), pairs[0].second);
	for (auto a : next)
	{
		std::cout << a << " ";
	}
	std::cout << std::endl;
}
#include "PmergeMe.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

std::vector<size_t> getJacobsthalNumbers(size_t number)
{
	size_t one = 0;
	size_t two = 1;
	std::vector<size_t> out;
	while (number-- > 0)
	{
		size_t c = two + 2 * one;
		one = two;
		two = c;
		out.push_back(two);
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
		for (size_t j = i; j < pairs.size(); j++)
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
	split_elements(vec, pairs);
	std::vector <size_t> next;
	for (auto a : pairs)
		next.push_back(a.first);

	sortVec(next);
	realignPairs(pairs, next);
	next.insert(next.begin(), pairs[0].second);
	std::vector<size_t> JacobsthalNumbers = getJacobsthalNumbers(next.size());
	size_t min = 0;
	size_t cap = 3;
	for (size_t i = 1; i < JacobsthalNumbers.size(); i++)
	{
		size_t end = std::min(pairs.size() - 1, JacobsthalNumbers[i] - 1);
		for (size_t j = end; j > min; j--)
		{
			size_t limit = std::min(next.size() - 1, cap);
			next.insert(std::upper_bound(next.begin(), next.begin() + limit, pairs[j].second), pairs[j].second);
		}
		min = end;
		cap = cap * 2 + 1;
	}
	if (vec.size() % 2 == 1)
		next.insert(std::upper_bound(next.begin(), next.end(), vec.back()), vec.back());
	vec = next;
}
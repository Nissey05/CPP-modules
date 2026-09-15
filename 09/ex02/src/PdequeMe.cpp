#include "PmergeMe.hpp"
#include <deque>
#include <iostream>
#include <algorithm>

std::deque<size_t> getJacobsthalNumbersDeque(size_t number)
{
	size_t one = 0;
	size_t two = 1;
	std::deque<size_t> out;
	while (number-- > 0)
	{
		size_t c = two + 2 * one;
		one = two;
		two = c;
		out.push_back(two);
	}
	return (out);
}

void split_elementsDeque(std::deque<size_t> &deque,
	std::deque<std::pair<size_t, size_t>> &pairs)
{
	if (deque.size() <= 1)
		return ;
	for (size_t i = 0; i < deque.size() && deque.size() - i != 1; i+= 2)
	{
		if (deque[i] < deque[i + 1])
			pairs.push_back(std::pair<size_t, size_t>(deque[i + 1], deque[i]));
		else
			pairs.push_back(std::pair<size_t, size_t>(deque[i], deque[i + 1]));
	}
}

void realignPairsDeque(std::deque<std::pair<size_t, size_t>> &pairs, std::deque<size_t> next)
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


void sortDeque(std::deque<size_t> &deque)
{
	if (deque.size() <= 1)
		return ;
	std::deque<std::pair<size_t, size_t>> pairs;
	split_elementsDeque(deque, pairs);
	std::deque <size_t> next;
	for (auto a : pairs)
		next.push_back(a.first);

	sortDeque(next);
	realignPairsDeque(pairs, next);
	next.insert(next.begin(), pairs[0].second);
	std::deque<size_t> JacobsthalNumbers = getJacobsthalNumbersDeque(next.size());
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
	if (deque.size() % 2 == 1)
		next.insert(std::upper_bound(next.begin(), next.end(), deque.back()), deque.back());
	deque = next;
}
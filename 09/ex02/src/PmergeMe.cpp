#include "PmergeMe.hpp"
#include <vector>

void split_elements(std::vector<size_t> &vec,
	std::vector<size_t> &small, std::vector<size_t> &big)
{
	if (vec.size() <= 1)
		return ;
	if (vec[0] < vec[1])
	{
		small.push_back(vec[0]);
		big.push_back(vec[1]);
	}
	else
	{
		small.push_back(vec[1]);
		big.push_back(vec[0]);
	}
	vec.pop();
	vec.pop();
	split_elements(vec, small, big);
}

void pieter(std::vector<size_t> &vec)
{
	std::vector<size_t> small, big;
	// 4 2 5 6 9 1
	split_elements(vec, small, big);
	// big sorten?
	// big 4 6 9
	// small 2 5 1
	
}
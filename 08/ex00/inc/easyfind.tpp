#pragma once

#include "easyfind.hpp"
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& c, int b)
{
	return (std::find(c.begin(), c.end(), b));
}
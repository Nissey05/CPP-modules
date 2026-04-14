#pragma once

#include "easyfind.hpp"
#include "NotFoundException.hpp"
#include <vector>

template <typename T>
void easyfind(T& c, int b)
{
	
	for (typename T::iterator i = c.begin(); i < c.end(); i++)
	{
		if (*i == b)
			return ;
	}
	throw NotFoundException();
}
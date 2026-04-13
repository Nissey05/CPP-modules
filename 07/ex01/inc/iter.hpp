#pragma once

#include <stddef.h>
#include <iostream>

template <typename T>
void	inc(T& node)
{
	node++;
}

template <typename T>
void	dec(T& node)
{
	node--;
}

template <typename T>
void	print(const T& node)
{
	std::cout << node << std::endl;
}

template <typename T, typename F>
void iter(T *c, const size_t len, F f)
{
	for (size_t i = 0; i < len; i++)
	{
		f(c[i]);
	}
}
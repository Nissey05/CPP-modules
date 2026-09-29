#include "Span.hpp"
#include <limits.h>
#include <iostream>
#include <algorithm>

Span::Span() :
N(0)
{}

Span::Span(unsigned int N) : 
N(N)
{}

Span::~Span()
{}

Span::Span(const Span &cpy) :
N(cpy.N)
{
	for (unsigned int i = 0; i < N; i++)
		data.push_back(cpy.data[i]);
}

Span &Span::operator=(const Span &cpy)
{
	if (this != &cpy)
	{
		N = cpy.N;
		for (unsigned int i = 0; i < N; i++)
			data.push_back(cpy.data[i]);
	}
	return (*this);
}

Span::Span(const Span &&old) :
data(old.data),
N(old.N)
{}

Span &Span::operator=(const Span &&old)
{
	if (this != &old)
	{
		data = old.data;
		N = old.N;
	}
	return (*this);
}

void Span::addNumber(int nb)
{
	if (data.size() >= N)
		throw FullSpanException();
	data.push_back(nb);
}

void Span::addRange(int min, int max)
{
	if (data.size() + (max - min) > N)
		throw FullSpanException();
	for (int i = min; i <= max; i++)
		data.push_back(i);
}

unsigned int Span::shortestSpan() const
{
	if (data.size() <= 1)
		throw NoSpanException();
	std::vector<int> cpy = data;
	unsigned int shortest = UINT_MAX;
	std::sort(cpy.begin(), cpy.end());
	for (unsigned int i = 0; i + 1 < cpy.size(); i++)
	{
		unsigned int span = cpy[i + 1] - cpy[i];
		if (span < shortest)
			shortest = span;
	}
	return (shortest);
}

unsigned int Span::longestSpan() const
{
	if (data.size() <= 1)
		throw NoSpanException();
	auto [min, max] = std::minmax_element(data.begin(), data.end());
	return (*max - *min);
}

const char *Span::NoSpanException::what() const noexcept
{
	return ("Span does not have enough entries.");
}

const char *Span::FullSpanException::what() const noexcept
{
	return ("Span is full.");
}
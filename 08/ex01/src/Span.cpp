#include "Span.hpp"
#include <limits.h>
#include <iostream>
#include <algorithm>

Span::Span() :
data(nullptr),
size(0),
N(0)
{}

Span::Span(unsigned int N) : 
size(0),
N(N)
{
	data = new int[N];
}

Span::~Span()
{}

Span::Span(const Span &cpy) :
size(cpy.size),
N(cpy.N)
{
	data = new int[N];
	for (unsigned int i = 0; i < N; i++)
		data[i] = cpy.data[i];
}

Span &Span::operator=(const Span &cpy)
{
	if (this != &cpy)
	{
		N = cpy.N;
		size = cpy.size;
		delete[] data;
		data = new int[N];
		for (unsigned int i = 0; i < N; i++)
			data[i] = cpy.data[i];
	}
	return (*this);
}

Span::Span(const Span &&old) :
data(old.data),
size(old.size),
N(old.N)
{}

Span &Span::operator=(const Span &&old)
{
	if (this != &old)
	{
		data = old.data;
		size = old.size;
		N = old.N;
	}
	return (*this);
}

void Span::addNumber(int nb)
{
	if (size >= N)
		throw FullSpanException();
	data[size++] = nb;
}

void Span::addRange(int min, int max)
{
	if (size + (max - min) > N)
		throw FullSpanException();
	for (int i = min; i <= max; i++)
	{
		data[size++] = i;
	}
}

unsigned int Span::shortestSpan() const
{
	if (size <= 1)
		throw NoSpanException();
	unsigned int shortest = UINT_MAX;
	std::sort(data, &data[size]);
	for (unsigned int i = 0; i + 1 < size; i++)
	{
		unsigned int span = data[i + 1] - data[i];
		if (span < shortest)
			shortest = span;
	}
	return (shortest);
}

unsigned int Span::longestSpan() const
{
	if (size <= 1)
		throw NoSpanException();
	int smallest = INT_MAX, largest = INT_MIN;
	for (unsigned int i = 0; i < size; i++)
	{
		if (data[i] < smallest)
			smallest = data[i];
		if (data[i] > largest)
			largest = data[i];
	}
	return (largest - smallest);
}

const char *Span::NoSpanException::what() const noexcept
{
	return ("Span does not have enough entries.");
}

const char *Span::FullSpanException::what() const noexcept
{
	return ("Span is full.");
}
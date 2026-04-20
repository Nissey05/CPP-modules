#include <iostream>
#include "Span.hpp"
#include <limits.h>

int main(void)
{
	Span s(7);

	s.addNumber(1000);
	s.addNumber(-1001);
	s.addNumber(14);
	std::cout << s.longestSpan() << std::endl;
	std::cout << s.shortestSpan() << std::endl;

	Span long_span(100000);

	long_span.addRange(-50000, 50000);
	std::cout << long_span.longestSpan() << std::endl;
	std::cout << long_span.shortestSpan() << std::endl;
}
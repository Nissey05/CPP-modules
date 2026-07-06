#pragma once
#include <exception>
#include <vector>

class Span
{
	private:
		std::vector<int> data;
		unsigned int N;
	public:
		Span();
		Span(unsigned int N);
		~Span();
		Span(const Span &cpy);
		Span &operator=(const Span &cpy);
		Span(const Span &&old);
		Span &operator=(const Span &&old);

		void addNumber(int nb);
		void addRange(int min, int max);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

		class NoSpanException : std::exception
		{
			virtual const char *what() const noexcept;
		};

		class FullSpanException : std::exception
		{
			virtual const char *what() const noexcept;
		};
};
#pragma once

#include <stddef.h>

template <typename T>
class Array
{
	private:
		T *data;
		size_t size_var;
	public:
		Array();
		Array(unsigned int n);
		~Array();
		Array(const Array &cpy);
		Array &operator=(const Array &cpy);
		Array(const Array &&cpy);
		Array &operator=(const Array &&cpy);

		T &operator[](size_t i) const;

		size_t size() const;

		class TooHighException : public std::exception
		{
			virtual const char *what() const noexcept;
		};
};

#include "Array.tpp"
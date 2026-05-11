#pragma once

#include <stddef.h>

template <typename T>
class Array
{
	private:
		T *data;
		size_t size_var;
	public:
		Array() noexcept;
		Array(unsigned int n);
		~Array() noexcept;
		Array(const Array &cpy);
		Array &operator=(const Array &cpy);
		Array(Array &&cpy) noexcept;
		Array &operator=(Array &&cpy) noexcept;

		T &operator[](size_t i) const;

		size_t size() const noexcept;

		class TooHighException : public std::exception
		{
			virtual const char *what() const noexcept;
		};
};

#include "Array.tpp"
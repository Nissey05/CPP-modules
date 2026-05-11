#include "Array.hpp"
#include <iostream>

template <typename T>
Array<T>::Array() noexcept :
data(nullptr),
size_var(0)
{}

template <typename T>
Array<T>::Array(unsigned int n) :
size_var(n)
{
	data = new T[n]();
}

template <typename T>
Array<T>::~Array() noexcept
{
	if (data)
		delete[] data;
}

template <typename T>
Array<T>::Array(const Array& copy)
{
	*this = copy;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& copy)
{
	if (this != &copy)
	{
		size_var = copy.size();
		if (data)
			delete[] data;
		data = new T[size_var];
		for (size_t i = 0; i < size_var; i++)
			data[i] = copy.data[i];
	}
	return (*this);
}

template <typename T>
Array<T>::Array(Array&& copy) noexcept
{
	size_var = copy.size();
	data = copy.data;
	copy.data = nullptr;
	copy.size_var = 0;
}

template <typename T>
Array<T>& Array<T>::operator=(Array&& copy) noexcept
{
	if (this != &copy)
	{
		if (data)
			delete[] data;
		size_var = copy.size();
		data = copy.data;
		copy.data = nullptr;
		copy.size_var = 0;
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](size_t i) const
{
	if (i >= size_var)
		throw Array<T>::TooHighException();
	return (data[i]);
}

template <typename T>
const char *Array<T>::TooHighException::what() const noexcept
{
	return ("Index is out of bounds (too high).");
}

template <typename T>
size_t Array<T>::size() const noexcept
{
	return (size_var);
}

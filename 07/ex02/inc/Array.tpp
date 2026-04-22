#include "Array.hpp"
#include <iostream>

template <typename T>
Array<T>::Array() :
data(nullptr),
size_var(0)
{}

template <typename T>
Array<T>::Array(unsigned int n) :
size_var(n)
{
	data = new T[n];
}

template <typename T>
Array<T>::~Array()
{
	size_var = copy.size();
	data = new T[size_var];
	for (size_t i = 0; i < size_var; i++)
		data[i] = copy.data[i];
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
Array<T>::Array(const Array&& copy)
{
	size_var = copy.size();
	data = new T[size_var];
	for (size_t i = 0; i < size_var; i++)
		data[i] = copy.data[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array&& copy)
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
size_t Array<T>::size() const
{
	return (size_var);
}

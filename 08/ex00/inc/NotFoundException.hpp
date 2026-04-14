#pragma once

#include <exception>

class NotFoundException : public std::exception
{
	virtual const char *what() const noexcept;
};
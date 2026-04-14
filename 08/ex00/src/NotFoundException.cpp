#include "NotFoundException.hpp"

const char *NotFoundException::what() const noexcept
{
	return ("Integer not found.");
}
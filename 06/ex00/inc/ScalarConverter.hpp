#pragma once

#include <string>

#define INT_MAX_FLOAT 2147483647.0
#define INT_MIN_FLOAT -2147483648.0

enum Types {
	Char,
	Int,
	Float,
	Double,
	None
};

class ScalarConverter
{
	private:
		ScalarConverter() = delete;
	public:
		static void convert(std::string str);
};

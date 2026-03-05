#pragma once

#include <string>

enum Types {
	Char,
	Int,
	Float,
	Double
};

class ScalarConverter
{
	private:
		ScalarConverter() = delete;
	public:
		static void convert(std::string str);
};

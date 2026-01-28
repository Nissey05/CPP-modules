#pragma once

#include "Fixed.hpp"

class	Point
{
	private:
		Fixed const x;
		Fixed const y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& cpy);
		~Point();

		Point&	operator=(const Point& cpy);
		Point operator-(const Point& other) const ;
		bool operator==(const Point& other) const;
		void print_vars(void) const;

		Fixed const &getX(void) const;
		Fixed const &getY(void) const;
};
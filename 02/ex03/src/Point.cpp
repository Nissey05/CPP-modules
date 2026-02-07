#include "Point.hpp"
#include <iostream>

Point::Point() : x(0), y(0)
{
	// std::cout << "Point default constructor called" << std::endl;
}

Point::Point(const float a, const float b) : x(a), y(b)
{
	// std::cout << "Point value constructor called" << std::endl;
}

Point::~Point()
{
	// std::cout << "Point default destructor called" << std::endl;

}

Point::Point(const Point& cpy) : x(cpy.x), y(cpy.y)
{
	// std::cout << "Point copy constructor called" << std::endl;
}

Point&	Point::operator=(const Point& cpy)
{
	// std::cout << "Point copy assignment operator called" << std::endl;
	if (&cpy == this)
		return (*this);
	return (*this);
}

void Point::print_vars(void) const
{
	std::cout << x << " " << y << std::endl;
}


Fixed const &Point::getX(void) const
{
	return (x);
}

Fixed const &Point::getY(void) const
{
	return (y);
}

Point Point::operator-(const Point& other) const {
	return (Point((x - other.x).toFloat(), (y - other.y).toFloat()));
}

bool Point::operator==(const Point& other) const {
	return ((x == other.x && y == other.y) ? true : false);
}
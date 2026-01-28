#include "Point.hpp"

// bool check_points(Point const a, Point const b, Point const point)
// {
// 	if (a.getX() < b.getX() && (point.getX() < a.getX() || point.getX() > b.getX()))

// }

float cross(Point const&u, Point const& v)
{
	return ((u.getX() * v.getY() - u.getY() * v.getX()).toFloat());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	if (a == b && a == c && !(a == point))
		return (false);
	Point const v1(point - a), v2(point - b), v3(point - c), ab(b - a), bc( c - b), ca(a - c);
	float c1 = cross(ab, v1);
	float c2 = cross(bc, v2);
	float c3 = cross(ca, v3);
	return (c1 >= 0 && c2 >= 0 && c3 >= 0) || (c1 <= 0 && c2 <= 0 && c3 <= 0);
}
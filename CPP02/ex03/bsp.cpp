#include "Point.hpp"

//Showlace formula
static Fixed	calculateArea(Point const p1, Point const p2, Point const p3)
{
	Fixed	area = (p1.getX() * (p2.getY() - p3.getY()) +
			p2.getX() * (p3.getY() - p1.getY()) +
			p3.getX() * (p1.getY() - p2.getY()));
	if (area < 0)
		return (area * -1);
	return (area);

}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	areaABC = calculateArea(a, b, c);
	
	Fixed	areaPAB = calculateArea(point, a, b);
	Fixed	areaPBC = calculateArea(point, b, c);
	Fixed	areaPAC = calculateArea(point, a, c);

	if (areaPAB == 0 || areaPBC == 0 || areaPAC == 0)
		return (false);
	return (areaPAB + areaPBC + areaPAC == areaABC);
}

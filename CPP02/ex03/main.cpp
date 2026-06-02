#include "Point.hpp"
#include <iostream>

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main( void )
{
	// a(0,0), b(10, 0), c(0, 10)
	Point const	a(0.0f, 0.0f);
	Point const	b(10.0f, 0.0f);
	Point const	c(0.0f, 10.0f);

	Point const	pInside(2.0f, 2.0f);
	//Point const	pOutside(20.0f, 20.0f);
	//Point const	pEdge(5.0f, 0.0f);

	std::cout << "Point inside (expected 1): \n" << bsp(a, b, c, pInside) << std::endl;
	//std::cout << "Point outside (expected 0): " << bsp(a, b, c, pOutside) << std::endl;
	//std::cout << "Point on the edge (expected 0): " << bsp(a, b, c, pEdge) << std::endl;

	return (0);
}

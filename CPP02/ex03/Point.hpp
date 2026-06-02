#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;
	public:
		// Orthodox Canonical Form
		Point( void );
		Point( const Point& other );
		Point&	operator=( const Point& other );
		~Point( void );

		// Additional Constructor
		Point( const float x, const float y );

		// Getters
		Fixed	getX( void ) const;
		Fixed	getY( void ) const;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 12:07:00 by admin             #+#    #+#             */
/*   Updated: 2026/08/04 20:58:57 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) { }

Point::Point(const float x, const float y) : _x(x), _y(y) { }

Point::Point(const Point &other) : _x(other._x), _y(other._y) { }

Point &Point::operator=(const Point &other)
{
	(void)other;
	return (*this);
}

Point::~Point() { }

float Point::getX() const
{
	return _x.toFloat();
}

float Point::getY() const
{
	return _y.toFloat();
}

static float findCross(Point const &a, Point const &b, Point const &point)
{
	float ABx = b.getX() - a.getX();
	float ABy = b.getY() - a.getY();
	float APx = point.getX() - a.getX();
	float APy = point.getY() - a.getY();
	
	return (ABx * APy) - ( ABy * APx);	
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float crossAB = findCross(a, b, point);
	float crossBC = findCross(b, c, point);
	float crossCA = findCross(c, a, point);

	if ((crossAB < 0 && crossBC < 0 && crossCA < 0)
		|| (crossAB > 0 && crossBC > 0 && crossCA > 0))
		return true;
	return false;
}

std::ostream &operator<<(std::ostream &os, const Point &other)
{
	os << "(" << other.getX() << ", " << other.getY() << ")";
	return os;
}
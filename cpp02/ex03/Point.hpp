/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 12:04:20 by admin             #+#    #+#             */
/*   Updated: 2026/08/04 17:46:38 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	const Fixed _x;
	const Fixed _y;
public:
	Point();
	Point(const float x, const float y);
	Point(const Point &other);
	Point& operator=(const Point &other);
	~Point();

	float getX() const;
	float getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
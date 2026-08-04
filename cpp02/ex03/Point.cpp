/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 12:07:00 by admin             #+#    #+#             */
/*   Updated: 2026/08/04 12:29:03 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) { }

Point::Point(const float x, const float y) : _x(x), _y(y) { }

Point::Point(const Point &other) : _x(other._x), _y(other._y) { }

Point& Point::operator=(const Point &other)
{
	return (*this);
}


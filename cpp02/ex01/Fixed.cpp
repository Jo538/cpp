/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 12:21:42 by jchartie          #+#    #+#             */
/*   Updated: 2026/07/31 18:09:22 by jchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int num) : fixedPoint(num << numFractBits) { }

Fixed::Fixed(const float num)
{
	fixedPoint = static_cast<int>(num * (1 << numFractBits));
}

Fixed::Fixed(const Fixed& other) : fixedPoint(other.fixedPoint)
{
	std::cout << "Copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		fixedPoint = other.fixedPoint;
	return *this;
}

Fixed::~Fixed() 
{
	std::cout << "Destructor called\n";
}

float Fixed::toFloat( void ) const
{
	int fnum = fixedPoint >> numFractBits;
	return static_cast<float>(fnum);
}

int Fixed::toInt( void ) const
{
	return fixedPoint >> numFractBits;	
}

void Fixed::setRawBits( int const raw )
{
	fixedPoint = raw;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return fixedPoint;
}

std::ostream &operator<<(std::ostream &os, const Fixed& other)
{
	return os << other.toFloat();
}
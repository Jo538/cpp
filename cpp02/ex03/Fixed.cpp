/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 12:21:42 by jchartie          #+#    #+#             */
/*   Updated: 2026/08/04 11:53:38 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0) { }

Fixed::Fixed(const int num) : fixedPoint(num << numFractBits) { }

Fixed::Fixed(const float num)
{
	fixedPoint = static_cast<int>(roundf(num * (1 << numFractBits)));
}

Fixed::Fixed(const Fixed& other) : fixedPoint(other.fixedPoint) { }

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		fixedPoint = other.fixedPoint;
	return *this;
}

Fixed::~Fixed() { }

float Fixed::toFloat( void ) const
{
	float fnum = static_cast<float>(fixedPoint); 
	return fnum / (1 << numFractBits);
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
	return fixedPoint;
}

std::ostream &operator<<(std::ostream &os, const Fixed& other)
{
	return os << other.toFloat();
}

bool Fixed::operator>(const Fixed &other) const
{
	if (this->fixedPoint > other.fixedPoint)
		return true;
	return false;
}

bool Fixed::operator<(const Fixed &other) const
{
	if (this->fixedPoint < other.fixedPoint)
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed &other) const
{
	if (this->fixedPoint >= other.fixedPoint)
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed &other) const
{
	if (this->fixedPoint <= other.fixedPoint)
		return true;
	return false;
}

bool Fixed::operator==(const Fixed &other) const
{
	if (this->fixedPoint == other.fixedPoint)
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed &other) const
{
	if (this->fixedPoint != other.fixedPoint)
		return true;
	return false;
}

float Fixed::operator+(const Fixed &other) const
{
	return this->toFloat() + other.toFloat();
}

float Fixed::operator-(const Fixed &other) const
{
	return this->toFloat() - other.toFloat();
}

float Fixed::operator*(const Fixed &other) const
{
	return this->toFloat() * other.toFloat();
}

float Fixed::operator/(const Fixed &other) const
{
	return this->toFloat() / other.toFloat();
}

Fixed& Fixed::operator++()
{
	this->fixedPoint++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->fixedPoint++;
	return temp;
}

Fixed& Fixed::operator--()
{
	this->fixedPoint--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->fixedPoint--;
	return temp;
}

Fixed& Fixed::min(Fixed& num1, Fixed& num2)
{
	if (num1.toFloat() <= num2.toFloat())
		return num1;
	else
		return num2;
}

Fixed& Fixed::max(Fixed& num1, Fixed& num2)
{
	if (num1.toFloat() >= num2.toFloat())
		return num1;
	else
		return num2;
}

const Fixed& Fixed::min(const Fixed& num1, const Fixed& num2)
{
	if (num1.toFloat() <= num2.toFloat())
		return num1;
	else
		return num2;
}

const Fixed& Fixed::max(const Fixed& num1, const Fixed& num2)
{
	if (num1.toFloat() >= num2.toFloat())
		return num1;
	else
		return num2;
}
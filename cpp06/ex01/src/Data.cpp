/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:10:20 by admin             #+#    #+#             */
/*   Updated: 2026/11/04 16:50:16 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"

Data::Data() : name("Pollux"), breed("Cairn Terrier"), age(7)
{
	std::cout << "Default constructor called" << std::endl;
}

Data::Data(const Data& other) : name(other.name), breed(other.breed), age(other.age)
{
	std::cout << "Copy constructor called" << std::endl;
}

Data& Data::operator=(const Data& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	
	this->name = other.name;
	this->breed = other.breed;
	this->age = other.age;
	
	return *this;
}

Data::~Data()
{
	std::cout << "Destructor called" << std::endl;
}

const std::string& Data::getName()
{
	return this->name;
}

const std::string& Data::getBreed()
{
	return this->breed;
}

int Data::getAge()
{
	return this->age;
}
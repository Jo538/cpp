/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:03:59 by admin             #+#    #+#             */
/*   Updated: 2026/11/04 17:59:03 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "A.hpp"

A::A()
{
	std::cout << "[A]" << " Default constructor called" << std::endl;
}

A::A(const A&)
{
	std::cout << "[A]" << " Copy constructor called" << std::endl;
}

A& A::operator=(const A&)
{
	std::cout << "[A]" << " Copy assignment operator called" << std::endl;
	return *this;
}

A::~A()
{
	std::cout << "[A]" << " Destructor called" << std::endl;
}
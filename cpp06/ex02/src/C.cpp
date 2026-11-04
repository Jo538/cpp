/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A copy.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:03:59 by admin             #+#    #+#             */
/*   Updated: 2026/11/04 18:06:29 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "C.hpp"

C::C()
{
	std::cout << "[C]" << " Default constructor called" << std::endl;
}

C::C(const C&)
{
	std::cout << "[C]" << " Copy constructor called" << std::endl;
}

C& C::operator=(const C&)
{
	std::cout << "[C]" << " Copy assignment operator called" << std::endl;
	return *this;
}

C::~C()
{
	std::cout << "[C]" << " Destructor called" << std::endl;
}
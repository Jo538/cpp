/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A copy.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:03:59 by admin             #+#    #+#             */
/*   Updated: 2026/11/04 18:05:33 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "B.hpp"

B::B()
{
	std::cout << "[B]" << " Default constructor called" << std::endl;
}

B::B(const B&)
{
	std::cout << "[B]" << " Copy constructor called" << std::endl;
}

B& B::operator=(const B&)
{
	std::cout << "[B]" << " Copy assignment operator called" << std::endl;
	return *this;
}

B::~B()
{
	std::cout << "[B]" << " Destructor called" << std::endl;
}
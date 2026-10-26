/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 20:24:52 by admin             #+#    #+#             */
/*   Updated: 2026/10/26 21:10:56 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "Test constructors" << std::endl;
	
	Bureaucrat one; // default
	Bureaucrat two("Yann Calvo Lopez", 42); // spec
	Bureaucrat three(two); // copy

	std::cout << one;
	std::cout << two;
	std::cout << three;

	std::cout << "Test Copy assignment operator" << std::endl;
	one = three;
	std::cout << one;

	
	std::cout << "Test increment/decrement" << std::endl;
	std::cout << ++one;
	std::cout << --one;

	std::cout << "Test deep copies" << std::endl;
	std::cout << ++two;
	std::cout << two;
	std::cout << three;

	std::cout << "Test destructor" << std::endl;
}
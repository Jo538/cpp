/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 20:24:52 by admin             #+#    #+#             */
/*   Updated: 2026/10/27 12:46:34 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
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

	// Test Exceptions
	std::cout << "Test Exceptions" << std::endl;
	try
	{
		Bureaucrat four("Jo", 150);
		std::cout << "Grade within range" << std::endl;
		Bureaucrat five("Pollux", 151);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}


	

	std::cout << "Test destructor" << std::endl;
}
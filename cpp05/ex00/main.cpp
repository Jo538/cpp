/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 20:24:52 by admin             #+#    #+#             */
/*   Updated: 2026/10/27 17:18:44 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "color.h"

int main(void)
{
	std::cout << BOLD << "----TEST CONSTRUCTORS----\n" << COLOR_DEFAULT;	
	Bureaucrat one; // default
	Bureaucrat two("Yann Calvo Lopez", 42); // spec
	Bureaucrat three(two); // copy

	std::cout << BOLD << "\n----TEST OVERLOAD OPERATOR << ----\n" << COLOR_DEFAULT;	
	std::cout << one << std::endl;
	std::cout << two << std::endl;
	std::cout << three << std::endl;

	std::cout << BOLD << "\n----TEST COPY ASSIGNMENT OPERATOR----\n" << COLOR_DEFAULT;
	std::cout << COLOR_GREEN << "Before assignment:\n" << COLOR_DEFAULT 
	"one --> " << one << std::endl << "three --> " << three << std::endl;	
	one = three;
	std::cout << COLOR_GREEN << "\nAfter assignment:\n" << COLOR_DEFAULT 
	"one --> " << one << std::endl;
	
	std::cout << BOLD << "\n----TEST INCREMENT/DECREMENT----\n" << COLOR_DEFAULT;
	std::cout << COLOR_MAGENTA << "Before increment: " COLOR_DEFAULT << two << std::endl;
	++two;
	std::cout << COLOR_MAGENTA << "After increment: " << COLOR_DEFAULT << two << std::endl;
	--two;
	std::cout << COLOR_MAGENTA << "After decrement: " << COLOR_DEFAULT << two << std::endl;

	std::cout << BOLD << "\n----TEST DEEP COPIES----\n" << COLOR_DEFAULT;
	std::cout << COLOR_BLUE << "Before increment of bureaucrat 2:\n" << COLOR_DEFAULT << 
	"two --> " << two << "\nthree --> " << three << std::endl;	
	++two;
	std::cout << COLOR_BLUE << "\nAfter increment of bureaucrat 2:\n" << COLOR_DEFAULT << 
	"two --> " << two << "\nthree --> " << three << std::endl;	

	// Test Exceptions
	std::cout << BOLD << "\n----TEST EXCEPTIONS----\n" << COLOR_DEFAULT;
	try
	{
		std::cout << COLOR_RED << "Test off limits instantiation of Bureaucrat(Pollux, 151)" << COLOR_DEFAULT << std::endl;
		Bureaucrat five("Pollux", 151);
		std::cout << "No issue to report" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << COLOR_RED << "\nTest decrementing one(Default Bureaucrat, 150) by 1, pushing it over the limit" << COLOR_DEFAULT<< std::endl;
		--one;
		std::cout << "No issue to report" << std::endl;		
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	

	std::cout << BOLD << "\n----TEST DESTRUCTORS----\n" << COLOR_DEFAULT;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 18:51:53 by admin             #+#    #+#             */
/*   Updated: 2026/11/12 12:47:02 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Span.hpp"
#include "color.h"

enum Constructor
{
	DEFAULT,
	SPEC,
	COPY
};

static void	section(int number, const std::string& title)
{
	const std::string	line = "══════════════════════════════════════════════";

	std::cout << "\n" << BOLD << line << "\n " << number << ". " << title
		<< "\n" << line << COLOR_DEFAULT << std::endl;
}

static void test(char c, unsigned int max, unsigned int set_size)
{
	std::cout << "\n" << BOLD << "▸ Span " << c
	<< " - max = " << max << ", set_size = " << set_size << COLOR_DEFAULT << std::endl;
}

static void printAttributes(const Span& item)
{
	std::cout << "max = " << item.getMax()
	<< ", set_size = " << item.getSetSize() << std::endl;	
}

static void printTestOutcome(const Span& item, unsigned int expected_max, size_t expected_set_size)
{
	if (item.getMax() == expected_max
		&& item.getSetSize() == expected_set_size)
		std::cout << COLOR_GREEN "✔ PASS";
	else
		std::cout << COLOR_RED "✘ FAIL";
	std::cout << COLOR_DEFAULT << std::endl;
}

int main(void)
{
	section(1, "Call Constructors");
	
	test('a', 10, 0);
	Span a;
	printAttributes(a);
	printTestOutcome(a, 10, 0);
	
	test('b', 100, 0);
	Span b(100);
	printAttributes(b);
	printTestOutcome(b, 100, 0);
	
	test('c', 100, 0);
	Span c(b);
	printAttributes(c);
	printTestOutcome(c, 100, 0);

	section(2, "Test addNumber()");
	// c: add 10 random numbers to c object
	for (int i = 0; i < 10; ++i)
		c.addNumber(std::rand() % 100);
	printAttributes(c);
	std::cout << c << std::endl;
	
	section(3, "Test assignment operator overload");
	std::cout << "\nb: " << b << std::endl; 
	std::cout << "c: " << c << std::endl; 

	b = c;
	
	std::cout << "\nb: " << b << std::endl; 
	std::cout << "c: " << c << std::endl; 

	section(4, "Test deep copies");
	std::cout << "\nb: " << b << std::endl; 
	std::cout << "c: " << c << std::endl; 

	for (int i = 0; i < 5; ++i)
		c.addNumber(std::rand() % 100);
	
	std::cout << "\nb: " << b << std::endl; 
	std::cout << "c: " << c << std::endl; 
	
	section(5, "Call Destructors");
}
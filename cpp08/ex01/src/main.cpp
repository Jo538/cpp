/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 18:51:53 by admin             #+#    #+#             */
/*   Updated: 2026/11/12 19:52:05 by admin            ###   ########.fr       */
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

static void test(std::string message)
{
	std::cout << "\n" << BOLD << "▸ " << message << COLOR_DEFAULT << std::endl;
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

static void addNumberRange(Span& obj, int size)
{
	for (int i = 0; i < size; ++i)
		obj.addNumber(std::rand() % 100);
}

int main(void)
{
	section(1, "Call Constructors");
	
	test("Span a - max = 10, set_size = 0");
	Span a;
	printAttributes(a);
	printTestOutcome(a, 10, 0);
	
	test("Span b - max = 100, set_size = 0");
	Span b(100);
	printAttributes(b);
	printTestOutcome(b, 100, 0);
	
	test("Span c - max = 100, set_size = 0");
	Span c(b);
	printAttributes(c);
	printTestOutcome(c, 100, 0);

	section(2, "Test addNumber()");
	test("Add 10 random numbers to empty c");
	std::cout << "before: " << c << std::endl;
	addNumberRange(c, 10);
	std::cout << "after: " << c << std::endl;
	
	section(3, "Test assignment operator overload");
	std::cout << "\nBefore -->\nb: " << b << std::endl; 
	std::cout << "c: " << c << std::endl; 

	b = c;
	
	std::cout << "\nAfter -->\nb: " << b << std::endl; 
	std::cout << "c: " << c << std::endl; 

	section(4, "Test deep copies");
	std::cout << "\nBefore change:\nb: " << b << std::endl; 
	std::cout << "c: " << c << std::endl; 

	addNumberRange(c, 5);
	
	std::cout << "\nAfter change\nb: " << b << std::endl; 
	std::cout << "c: " << c << std::endl; 

	section(5, "Test 10,000 numbers");
	test("Span d - max = 10000, set_size = 10000");
	Span d(10000);
	addNumberRange(d, 10000);
	printAttributes(d);
	printTestOutcome(d, 10000, 10000);
	
	section(6, "Add number to full set");
	try
	{
		d.addNumber(42);
	}
	catch(const std::out_of_range& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	section(7, "Test longestSpan()");
	test("call longestSpan() on b");
	std::cout << "max = " << b.longestSpan() << std::endl;

	section(8, "Test shortestSpan()");
	test("call shortestSpan() on b");
	std::cout << "min = " << b.shortestSpan() << std::endl;

	section(9, "Test shortestSpan() on empty set");
	try
	{
		std::cout << a.shortestSpan() << std::endl;
	}
	catch (std::logic_error& e)
	{
		std::cerr << e.what() << std::endl;
	}

	section(10, "Test addRange()");
	test("call addRange() from arr = [42, 24, 2001]");
	int arr[] = {42, 24, 2001};
	a.addRange(arr, arr + 3);
	std::cout << "a: " << a << std::endl;

	section(11, "Call Destructors");
}
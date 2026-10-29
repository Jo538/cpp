/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 20:24:52 by admin             #+#    #+#             */
/*   Updated: 2026/10/29 11:47:50 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "color.h"

/* ---------------------------- output helpers ---------------------------- */

static void	section(int number, const std::string& title)
{
	const std::string	line = "══════════════════════════════════════════════";

	std::cout << "\n" << BOLD << line << "\n " << number << ". " << title
		<< "\n" << line << COLOR_DEFAULT << std::endl;
}

// "▸ what is being tested"
static void	test(const std::string& what)
{
	std::cout << BOLD << "▸ " << what << COLOR_DEFAULT << std::endl;
}

// Indented label in a fixed-width column, e.g. "  before   one   : "
static void	label(const std::string& step, const std::string& name)
{
	std::string	s = step;
	std::string	n = name;

	s.resize(8, ' ');
	n.resize(5, ' ');
	std::cout << "  " << s << " " << n << " : ";
}

static void	expected(const std::string& what)
{
	std::cout << "  expected : " << what << std::endl;
}

static void	got(const std::string& what, bool pass)
{
	std::cout << "  got      : " << what << "   "
		<< (pass ? COLOR_GREEN "✔ PASS" : COLOR_RED "✘ FAIL")
		<< COLOR_DEFAULT << std::endl;
}

/* --------------------------------- tests -------------------------------- */

int main(void)
{
	section(1, "CONSTRUCTORS");
	Bureaucrat one; // default
	Bureaucrat two("Yann Calvo Lopez", 42); // spec
	Bureaucrat three(two); // copy

	Form a; // default
	Form b("AZ - 5", 42, 52); // spec
	Form c(b); // copy

	section(2, "INSERTION OPERATOR <<");
	label("", "two");	std::cout << two << std::endl;
	label("", "b");		std::cout << b << std::endl;

	section(3, "COPY ASSIGNMENT");
	test("one = three");
	label("before", "one");		std::cout << one << std::endl;
	label("", "three");			std::cout << three << std::endl;
	one = three;
	label("after", "one");		std::cout << one << std::endl;

	std::cout << std::endl;
	test("a = c");
	label("before", "a");		std::cout << a << std::endl;
	c.beSigned(two);
	label("", "c");				std::cout << c << std::endl;
	a = c;
	label("after", "a");		std::cout << a << std::endl;

	section(4, "INCREMENT / DECREMENT");
	test("++two, then --two");
	label("before", "two");		std::cout << two << std::endl;
	++two;
	label("after ++", "two");	std::cout << two << std::endl;
	--two;
	label("after --", "two");	std::cout << two << std::endl;

	section(5, "DEEP COPIES");
	test("++two must not change three (copied from two)");
	label("before", "two");		std::cout << two << std::endl;
	label("", "three");			std::cout << three << std::endl;
	++two;
	label("after", "two");		std::cout << two << std::endl;
	label("", "three");			std::cout << three << std::endl;

	section(6, "EXCEPTIONS");
	test("Bureaucrat(\"Pollux\", 151)");
	expected("GradeTooLowException");
	try
	{
		Bureaucrat five("Pollux", 151);
		got("no exception", false);
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		got(e.what(), true);
	}
	catch (std::exception& e)
	{
		got(e.what(), false);
	}

	std::cout << std::endl;
	test("--four");
	Bureaucrat four("Pollux", 150);
	label("before", "four");		std::cout <<  four << std::endl;
	expected("GradeTooLowException");
	try
	{
		--four;
		got("no exception", false);
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		got(e.what(), true);
	}
	catch (std::exception& e)
	{
		got(e.what(), false);
	}

	std::cout << std::endl;
	test("Form(\"AZ-5\", 151, 42)");
	expected("GradeTooLowException");
	try
	{
		Form d("AZ-5", 151, 42);
		got("no exception", false);
	}
	catch (Form::GradeTooLowException& e)
	{
		got(e.what(), true);
	}
	catch (std::exception& e)
	{
		got(e.what(), false);
	}

	std::cout << std::endl;
	test("beSigned() on Bureaucrat with grades too low");
	expected("GradeTooLowException");
	try
	{
		Form d("AZ-5", 42, 42);
		Bureaucrat six("Havana", 52);
		d.beSigned(six);
		got("no exception", false);
	}
	catch (Form::GradeTooLowException& e)
	{
		got(e.what(), true);
	}
	catch (std::exception& e)
	{
		got(e.what(), false);
	}

	std::cout << std::endl;
	test("signForm() on Form");
	expected("No exception");
	try
	{
		Form e("AZ-5", 42, 42);
		Bureaucrat seven("Havana", 32);
		seven.signForm(e);
		got("no exception", true);
	}
	catch (Form::GradeTooLowException& e)
	{
		got(e.what(), true);
	}
	catch (std::exception& e)
	{
		got(e.what(), false);
	}

	std::cout << std::endl;
	test("signForm() on Form but Bureaucrat's grade too low");
	expected("GradeTooLowException");
	try
	{
		Form e("AZ-5", 42, 42);
		Bureaucrat seven("Havana", 52);
		seven.signForm(e);
		got("no exception", false);
	}
	catch (Form::GradeTooLowException& e)
	{
		got(e.what(), true);
	}
	catch (std::exception& e)
	{
		got(e.what(), false);
	}

	section(7, "DESTRUCTORS");
}

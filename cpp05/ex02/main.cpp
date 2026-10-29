/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 20:24:52 by admin             #+#    #+#             */
/*   Updated: 2026/10/29 18:38:39 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "color.h"

/* ---------------------------- output helpers ---------------------------- */

static void	section(int number, const std::string& title)
{
	const std::string	line = "══════════════════════════════════════════════";

	std::cout << "\n" << BOLD << line << "\n " << number << ". " << title
		<< "\n" << line << COLOR_DEFAULT << std::endl;
}

// // "▸ what is being tested"
// static void	test(const std::string& what)
// {
// 	std::cout << BOLD << "▸ " << what << COLOR_DEFAULT << std::endl;
// }

// // Indented label in a fixed-width column, e.g. "  before   one   : "
// static void	label(const std::string& step, const std::string& name)
// {
// 	std::string	s = step;
// 	std::string	n = name;

// 	s.resize(8, ' ');
// 	n.resize(5, ' ');
// 	std::cout << "  " << s << " " << n << " : ";
// }

// static void	expected(const std::string& what)
// {
// 	std::cout << "  expected : " << what << std::endl;
// }

// static void	got(const std::string& what, bool pass)
// {
// 	std::cout << "  got      : " << what << "   "
// 		<< (pass ? COLOR_GREEN "✔ PASS" : COLOR_RED "✘ FAIL")
// 		<< COLOR_DEFAULT << std::endl;
// }

/* --------------------------------- tests -------------------------------- */

int main(void)
{
	section(1, "CONSTRUCTORS");
	Bureaucrat one; // default
	Bureaucrat two("Yann Calvo Lopez", 42); // spec
	Bureaucrat three(two); // copy

	ShrubberyCreationForm a;
	ShrubberyCreationForm b("target");
	ShrubberyCreationForm c(b);

	RobotomyRequestForm four;
	RobotomyRequestForm five("target");
	RobotomyRequestForm six(five);

	section(2, "TRIGGER ACTION SHRUBBERY");
	a.action();

	section(3, "TRIGGER ACTION ROBOTOMY");
	five.action();
	four.action();
	
	section(3, "DESTRUCTORS");
}
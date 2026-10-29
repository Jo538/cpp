/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 20:24:52 by admin             #+#    #+#             */
/*   Updated: 2026/10/29 20:56:02 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
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
	std::cout << "\n" << BOLD << "▸ " << what << COLOR_DEFAULT << std::endl;
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
	Bureaucrat	boss("Boss", 1);
	Bureaucrat	intern("Intern", 150);

	ShrubberyCreationForm	shrub("home");
	RobotomyRequestForm		robot("Bender");
	PresidentialPardonForm	pardon("Arthur Dent");

	test("Print the forms with <<");
	label("", "shrub");		std::cout << shrub << std::endl;
	label("", "robot");		std::cout << robot << std::endl;
	label("", "pardn");		std::cout << pardon << std::endl;

	/* ------------------------------------------------------------------ */
	section(2, "SIGNING");

	test("Intern (grade 150) signs the shrubbery form (needs 145)");
	expected("not signed");
	intern.signForm(shrub);
	got(shrub.isSigned() ? "signed" : "not signed", !shrub.isSigned());

	test("Boss (grade 1) signs the shrubbery form (needs 145)");
	expected("signed");
	boss.signForm(shrub);
	got(shrub.isSigned() ? "signed" : "not signed", shrub.isSigned());

	/* ------------------------------------------------------------------ */
	section(3, "EXECUTING AN UNSIGNED FORM");

	test("Boss executes the robotomy form, which nobody signed yet");
	expected("AForm::FormNotSigned");
	try
	{
		robot.execute(boss);
		got("no exception", false);
	}
	catch (AForm::FormNotSigned& e)
	{
		got(e.what(), true);
	}
	catch (std::exception& e)
	{
		got(e.what(), false);
	}

	/* ------------------------------------------------------------------ */
	section(4, "EXECUTING WITH A GRADE TOO LOW");

	test("Intern (grade 150) executes the signed shrubbery form (needs 137)");
	expected("Bureaucrat::GradeTooLowException");
	try
	{
		shrub.execute(intern);
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

	/* ------------------------------------------------------------------ */
	section(5, "SUCCESSFUL EXECUTIONS");

	test("Boss executes the shrubbery form");
	expected("a file home_shrubbery appears in this folder (open it to check)");
	boss.executeForm(shrub);

	test("Boss signs and executes the robotomy form 4 times");
	expected("about half successes, half failures");
	boss.signForm(robot);
	boss.executeForm(robot);
	boss.executeForm(robot);
	boss.executeForm(robot);
	boss.executeForm(robot);

	test("Boss signs and executes the presidential pardon form");
	expected("Arthur Dent was pardoned by Zaphod Beeblebrox");
	boss.signForm(pardon);
	boss.executeForm(pardon);

	/* ------------------------------------------------------------------ */
	section(6, "FILE THAT CAN'T BE CREATED");

	test("Shrubbery form whose target is in a folder that doesn't exist");
	ShrubberyCreationForm	nowhere("no_such_folder/home");
	boss.signForm(nowhere);
	expected("std::runtime_error");
	try
	{
		nowhere.execute(boss);
		got("no exception", false);
	}
	catch (std::runtime_error& e)
	{
		got(e.what(), true);
	}
	catch (std::exception& e)
	{
		got(e.what(), false);
	}

	/* ------------------------------------------------------------------ */
	section(7, "INTERN TESTS");

	test("Form TEST doesn't exist");
	Intern Greg;
	AForm *new_form;
	try
	{
		new_form = Greg.makeForm("TEST", "Ben");
	}
	catch(const Intern::InexistantForm& e)
	{
		std::cout << e.what() << std::endl;
	}

	test("Form Shrubby exists");
	try
	{
		new_form = Greg.makeForm("Shrubbery", "Ben");
	}
	catch(const Intern::InexistantForm& e)
	{
		std::cout << e.what() << std::endl;
	}

	delete new_form;
	
	/* ------------------------------------------------------------------ */
	section(8, "COPIES");

	test("Copy of the signed pardon form (target: Arthur Dent)");
	PresidentialPardonForm	pardonCopy(pardon);
	expected("signed, and Arthur Dent is pardoned again");
	label("", "copy");		std::cout << pardonCopy << std::endl;
	boss.executeForm(pardonCopy);

	section(8, "DESTRUCTORS");
}

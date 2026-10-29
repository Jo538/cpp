/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 20:08:03 by admin             #+#    #+#             */
/*   Updated: 2026/10/29 20:55:24 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "color.h"

Intern::Intern()
{
	std::cout << "  " << COLOR_ORANGE << "[Intern] " << COLOR_DEFAULT << DIM << "Default constructor called" << COLOR_DEFAULT << std::endl;	
}
Intern::Intern(const Intern& other)
{
	(void)other;
	std::cout << "  " << COLOR_ORANGE << "[Intern] " << COLOR_DEFAULT << DIM << "Copy constructor called" << COLOR_DEFAULT << std::endl;		
}
	
Intern::~Intern()
{
	std::cout << "  " << COLOR_ORANGE << "[Intern] " << COLOR_DEFAULT << DIM << "Destructor called" << COLOR_DEFAULT << std::endl;	
}

const Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	std::cout << "  " << COLOR_ORANGE << "[Intern] " << COLOR_DEFAULT << DIM << "Copy Assignment Operator called" << COLOR_DEFAULT << std::endl;		
	return *this;
}

static AForm *makeShrubbery(const std::string& target)
{
	return (new ShrubberyCreationForm(target)); 
}

static AForm *makeRobotomy(const std::string& target)
{
	return (new RobotomyRequestForm(target)); 
}

static AForm *makePresidential(const std::string& target)
{
	return (new PresidentialPardonForm(target)); 
}

const char *Intern::InexistantForm::what() const throw()
{
	return "Form name doesn't exist.";
}

AForm *Intern::makeForm(const std::string& form_name, const std::string& form_target)
{
	std::string array[3] = {"Shrubbery", "Robotomy", "Presidential"};
	AForm *(*func[3])(const std::string& target) = {makeShrubbery, makeRobotomy, makePresidential};
	
	for (int i = 0; i < 3; i++)
	{
		if (form_name == array[i])
		{
			std::cout << "Intern creates " << form_name << ".\n";
			return (func[i](form_target));			
		}
	}
	throw InexistantForm();
}
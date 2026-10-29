/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 12:08:29 by admin             #+#    #+#             */
/*   Updated: 2026/10/29 14:30:03 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "color.h"

const int RobotomyRequestForm::_GRADE_SIGN;
const int RobotomyRequestForm::_GRADE_EXEC;

RobotomyRequestForm::RobotomyRequestForm() : AForm("Shrubbery", _GRADE_SIGN, _GRADE_EXEC), _target("Default")
{
	std::cout << "  " << COLOR_RED << "[ShrubberyCreationAForm]       " << COLOR_DEFAULT << DIM << "Default constructor called" << COLOR_DEFAULT << std::endl;
}	

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target("Default")
{
	std::cout << "  " << COLOR_RED << "[ShrubberyCreationAForm]       " << COLOR_DEFAULT << DIM << "Copy constructor called" << COLOR_DEFAULT << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Shrubbery", _GRADE_SIGN, _GRADE_EXEC), _target(target)
{
	std::cout << "  " << COLOR_RED << "[ShrubberyCreationAForm]       " << COLOR_DEFAULT << DIM << "Spec constructor called" << COLOR_DEFAULT << std::endl;	
}	

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "  " << COLOR_RED << "[ShrubberyCreationAForm]       " << COLOR_DEFAULT << DIM << "Destructor called" << COLOR_DEFAULT << std::endl;
}

void RobotomyRequestForm::action() const
{

}
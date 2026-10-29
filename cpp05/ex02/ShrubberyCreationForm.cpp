/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationAForm.cpp                          :+:      :+:    :+:   */
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
#include "ShrubberyCreationForm.hpp"
#include "color.h"

const int ShrubberyCreationForm::_GRADE_SIGN;
const int ShrubberyCreationForm::_GRADE_EXEC;

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", _GRADE_SIGN, _GRADE_EXEC), _target("Default")
{
	std::cout << "  " << COLOR_RED << "[ShrubberyCreationAForm]       " << COLOR_DEFAULT << DIM << "Default constructor called" << COLOR_DEFAULT << std::endl;
}	

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target("Default")
{
	std::cout << "  " << COLOR_RED << "[ShrubberyCreationAForm]       " << COLOR_DEFAULT << DIM << "Copy constructor called" << COLOR_DEFAULT << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery", _GRADE_SIGN, _GRADE_EXEC), _target(target)
{
	std::cout << "  " << COLOR_RED << "[ShrubberyCreationAForm]       " << COLOR_DEFAULT << DIM << "Spec constructor called" << COLOR_DEFAULT << std::endl;	
}	

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "  " << COLOR_RED << "[ShrubberyCreationAForm]       " << COLOR_DEFAULT << DIM << "Destructor called" << COLOR_DEFAULT << std::endl;
}

void ShrubberyCreationForm::action() const
{
	std::string tmp = this->_target + "_shrubbery";
	std::ofstream outFile(tmp.c_str());

	outFile <<
	"         v" << std::endl <<
	"        >X<" << std::endl <<
	"         A" << std::endl <<
	"        d$b" << std::endl <<
	"      .d\\$$b." << std::endl <<
	"    .d$i$$\\$$b." << std::endl <<
	"       d$$@b" << std::endl <<
	"      d\\$$$ib" << std::endl <<
	"    .d$$$\\$$$b" << std::endl <<
	"  .d$$@$$$$\\$$ib." << std::endl <<
	"      d$$i$$b" << std::endl <<
	"     d\\$$$$@$b" << std::endl <<
	"  .d$@$$\\$$$$$@b." << std::endl <<
	".d$$$$i$$$\\$$$$$$b." << std::endl <<
	"        ###" << std::endl <<
	"        ###" << std::endl <<
	"        ###" << std::endl <<
	std::endl;
	outFile.close();
}
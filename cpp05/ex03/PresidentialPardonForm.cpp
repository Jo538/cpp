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
#include "PresidentialPardonForm.hpp"
#include "color.h"

const int PresidentialPardonForm::_GRADE_SIGN;
const int PresidentialPardonForm::_GRADE_EXEC;

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", _GRADE_SIGN, _GRADE_EXEC), _target("Default")
{
	std::cout << "  " << COLOR_GREEN << "[PresidentialForm]       " << COLOR_DEFAULT << DIM << "Default constructor called" << COLOR_DEFAULT << std::endl;
}	

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target)
{
	std::cout << "  " << COLOR_GREEN << "[PresidentialForm]       " << COLOR_DEFAULT << DIM << "Copy constructor called" << COLOR_DEFAULT << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Presidential Pardon", _GRADE_SIGN, _GRADE_EXEC), _target(target)
{
	std::cout << "  " << COLOR_GREEN << "[PresidentialForm]       " << COLOR_DEFAULT << DIM << "Spec constructor called" << COLOR_DEFAULT << std::endl;	
}	

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "  " << COLOR_GREEN << "[PresidentialForm]       " << COLOR_DEFAULT << DIM << "Destructor called" << COLOR_DEFAULT << std::endl;
}

void PresidentialPardonForm::action() const
{
	std::cout << this->_target << " was pardoned by Zaphod Beeblebrox." << std::endl;
}
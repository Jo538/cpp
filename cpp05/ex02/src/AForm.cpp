/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 17:46:48 by admin             #+#    #+#             */
/*   Updated: 2026/10/29 15:24:04 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "color.h"

AForm::AForm() : _name("Default AForm"), _is_signed(false), _grade_sign(1), _grade_execute(1)
{
	std::cout << "  " << COLOR_CYAN << "[AForm]       " << COLOR_DEFAULT << DIM << "Default constructor called" << COLOR_DEFAULT << std::endl;
}

AForm::AForm(const AForm& other) : _name(other._name), _is_signed(other._is_signed), _grade_sign(other._grade_sign), _grade_execute(other._grade_execute)
{
	std::cout << "  " << COLOR_CYAN << "[AForm]       " << COLOR_DEFAULT << DIM << "Copy constructor called" << COLOR_DEFAULT << std::endl;
}

AForm::AForm(const std::string name, const int grade_sign, const int grade_execute) : _name(name), _is_signed(false), _grade_sign(grade_sign), _grade_execute(grade_execute)
{
	std::cout << "  " << COLOR_CYAN << "[AForm]       " << COLOR_DEFAULT << DIM << "Spec constructor called" << COLOR_DEFAULT << std::endl;
	if (_grade_execute < 1 || _grade_sign < 1)
		throw GradeTooHighException();
	if (_grade_execute > 150 || _grade_sign > 150)
		throw GradeTooLowException();		
}

AForm::~AForm()
{
	std::cout << "  " << COLOR_CYAN << "[AForm]       " << COLOR_DEFAULT << DIM << "Destructor called" << COLOR_DEFAULT << std::endl;
}

const AForm& AForm::operator=(const AForm& other)
{
	std::cout << "  " << COLOR_CYAN << "[AForm]       " << COLOR_DEFAULT << DIM << "Copy assignment operator overload called" << COLOR_DEFAULT << std::endl;
	_is_signed = other._is_signed;
	return *this;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "AForm: Error: Grade too high.";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "AForm: Error: Grade too low.";
}

const char *AForm::FormNotSigned::what() const throw()
{
	return "AForm: Error: Form not signed.";
}

const std::string& AForm::getName() const
{
	return _name;
}

int AForm::isSigned() const
{
	return _is_signed;
}

int AForm::getGradeSign() const
{
	return _grade_sign;
}

int AForm::getGradeExecute() const
{
	return _grade_execute;
}

std::ostream& operator<<(std::ostream& os, const AForm& AForm)
{
	os << COLOR_CYAN << "[AForm] " << COLOR_DEFAULT << AForm.getName() << " [";
	if (!AForm.isSigned())
		os << "NOT ";
	os << "signed] (sign: " << AForm.getGradeSign()
	<< ", exec: " << AForm.getGradeExecute() << ")";
	return os;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (_grade_sign < bureaucrat.getGrade())
		throw GradeTooLowException();
	_is_signed = true;
}

void AForm::execute(Bureaucrat const& executor) const
{
	if (_is_signed == false )
		throw FormNotSigned();
	if (executor.getGrade() > this->getGradeExecute())
		throw Bureaucrat::GradeTooLowException();
	action();
}
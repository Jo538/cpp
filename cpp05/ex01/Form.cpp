/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 17:46:48 by admin             #+#    #+#             */
/*   Updated: 2026/10/29 11:41:50 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "color.h"

Form::Form() : _name("Default Form"), _is_signed(false), _grade_sign(1), _grade_execute(1)
{
	std::cout << "  " << COLOR_CYAN << "[Form]       " << COLOR_DEFAULT << DIM << "Default constructor called" << COLOR_DEFAULT << std::endl;
}

Form::Form(const Form& other) : _name(other._name), _is_signed(other._is_signed), _grade_sign(other._grade_sign), _grade_execute(other._grade_execute)
{
	std::cout << "  " << COLOR_CYAN << "[Form]       " << COLOR_DEFAULT << DIM << "Copy constructor called" << COLOR_DEFAULT << std::endl;
}

Form::Form(const std::string name, const int grade_sign, const int grade_execute) : _name(name), _is_signed(false), _grade_sign(grade_sign), _grade_execute(grade_execute)
{
	std::cout << "  " << COLOR_CYAN << "[Form]       " << COLOR_DEFAULT << DIM << "Spec constructor called" << COLOR_DEFAULT << std::endl;
	if (_grade_execute < 1 || _grade_sign < 1)
		throw GradeTooHighException();
	if (_grade_execute > 150 || _grade_sign > 150)
		throw GradeTooLowException();		
}

Form::~Form()
{
	std::cout << "  " << COLOR_CYAN << "[Form]       " << COLOR_DEFAULT << DIM << "Destructor called" << COLOR_DEFAULT << std::endl;
}

const Form& Form::operator=(const Form& other)
{
	std::cout << "  " << COLOR_CYAN << "[Form]       " << COLOR_DEFAULT << DIM << "Copy assignment operator overload called" << COLOR_DEFAULT << std::endl;
	_is_signed = other._is_signed;
	return *this;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Form: Error: Grade too high.";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form: Error: Grade too low.";
}

const std::string& Form::getName() const
{
	return _name;
}

int Form::isSigned() const
{
	return _is_signed;
}

int Form::getGradeSign() const
{
	return _grade_sign;
}

int Form::getGradeExecute() const
{
	return _grade_execute;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << COLOR_CYAN << "[Form] " << COLOR_DEFAULT << form.getName() << " [";
	if (!form.isSigned())
		os << "NOT ";
	os << "signed] (sign: " << form.getGradeSign()
	<< ", exec: " << form.getGradeExecute() << ")";
	return os;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (_grade_sign < bureaucrat.getGrade())
		throw GradeTooLowException();
	_is_signed = true;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 17:46:48 by admin             #+#    #+#             */
/*   Updated: 2026/10/29 10:38:38 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"

Form::Form() : _name("Default Form"), _is_signed(false), _grade_sign(1), _grade_execute(1)
{
	std::cout << "Form: Default Constructor called" << std::endl;
}

Form::Form(const Form& other) : _name(other._name), _is_signed(other._is_signed), _grade_sign(other._grade_sign), _grade_execute(other._grade_execute)
{
	std::cout << "Form: Copy Constructor called" << std::endl;
}

Form::Form(const std::string name, const int grade_sign, const int grade_execute) : _name(name), _is_signed(false), _grade_sign(grade_sign), _grade_execute(grade_execute)
{
	std::cout << "Form: Spec Constructor called" << std::endl;
	if (_grade_execute < 1 || _grade_sign < 1)
		throw GradeTooHighException();
	if (_grade_execute > 150 || _grade_sign > 150)
		throw GradeTooLowException();		
}

Form::~Form()
{
	std::cout << "Form: Destructor called" << std::endl;
}

const Form& Form::operator=(const Form& other)
{
	std::cout << "Form: Copy Assignment Operator Overload called" << std::endl;
	_is_signed = other._is_signed;
	return *this;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Form: Error: Grade too high.";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "the bureaucrat grade is too low";
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
	os << "Form " << form.getName() << " is ";
	if (form.isSigned())
		os << "NOT ";
	os << "signed. This form can only be executed by a bureaucrat of grade "
	<< form.getGradeExecute() << " or higher, and signed by a bureaucrat of grade "
	<< form.getGradeSign() << " or higher" << std::endl;
	return os;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (_grade_sign > bureaucrat.getGrade())
		throw GradeTooLowException();
	_is_signed = true;
}
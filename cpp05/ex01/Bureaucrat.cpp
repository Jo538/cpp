/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 20:00:22 by admin             #+#    #+#             */
/*   Updated: 2026/10/29 19:37:46 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "color.h"

Bureaucrat::Bureaucrat() : _name("Default Bureaucrat"), _grade(150) 
{
	std::cout << "  " << COLOR_YELLOW << "[Bureaucrat] " << COLOR_DEFAULT << DIM << "Default constructor called" << COLOR_DEFAULT << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "  " << COLOR_YELLOW << "[Bureaucrat] " << COLOR_DEFAULT << DIM << "Spec constructor called" << COLOR_DEFAULT << std::endl;
	if (_grade > 150)
		throw GradeTooLowException();
	if (_grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "  " << COLOR_YELLOW << "[Bureaucrat] " << COLOR_DEFAULT << DIM << "Destructor called" << COLOR_DEFAULT << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
	std::cout << "  " << COLOR_YELLOW << "[Bureaucrat] " << COLOR_DEFAULT << DIM << "Copy constructor called" << COLOR_DEFAULT << std::endl;	
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) //TODO: _name is a const so can't reassign it. Is what I've done correct?
{
	std::cout << "  " << COLOR_YELLOW << "[Bureaucrat] " << COLOR_DEFAULT << DIM << "Copy assignment operator called" << COLOR_DEFAULT << std::endl;	
	this->_grade = other._grade;
	return *this;
}

Bureaucrat& Bureaucrat::operator++()
{
	this->_grade--;
	if (this->_grade < 1)
		throw GradeTooHighException();
	return *this;
}

Bureaucrat& Bureaucrat::operator--()
{
	this->_grade++;
	if (this->_grade > 150)
		throw GradeTooLowException();
	return *this;
}

const std::string& Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << COLOR_YELLOW << "[Bureaucrat] " << COLOR_DEFAULT << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat: Error: Grade too high.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat: Error: Grade too low.";
}

void Bureaucrat::signForm(Form& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << _name << " couldn't sign " << form.getName()
		<< " because " << e.what() << std::endl;
	}
}
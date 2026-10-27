/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 20:00:22 by admin             #+#    #+#             */
/*   Updated: 2026/10/27 12:47:03 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default Bureaucrat"), _grade(150) 
{
	std::cout << "Bureaucrat: Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat: Spec Constructor called" << std::endl;
	if (_grade > 150)
		throw GradeTooLowException();
	if (_grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat: Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat: Copy Constructor called" << std::endl;	
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) //TODO: _name is a const so can't reassign it. Is what I've done correct?
{
	std::cout << "Bureaucrat: Copy Assignment Operator called" << std::endl;	
	this->_grade = other._grade;
	return *this;
}

Bureaucrat& Bureaucrat::operator++()
{
	this->_grade--;
	return *this;
}

Bureaucrat& Bureaucrat::operator--()
{
	this->_grade++;
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
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".\n";
	return os;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Error: Grade too high.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Error: Grade too low.";
}
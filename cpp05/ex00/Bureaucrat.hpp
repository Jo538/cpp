/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 19:51:27 by admin             #+#    #+#             */
/*   Updated: 2026/10/27 12:38:08 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;

public:
	// Constructors
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& other);

	// Destructor
	~Bureaucrat();
	
	// Overload Operations
	Bureaucrat& operator=(const Bureaucrat& other);
	Bureaucrat& operator++(); //TODO: why return a ref to bureaucrat object?
	Bureaucrat& operator--(); //TODO: why return a ref to bureaucrat object?
	
	// Getters
	const std::string& getName() const;
	int getGrade() const;

	// Nested Classes
	class GradeTooHighException;
	class GradeTooLowException;
};

class Bureaucrat::GradeTooHighException : public std::exception
{
public:
	const char *what() const throw();
};

class Bureaucrat::GradeTooLowException : public std::exception
{
public:
	const char *what() const throw();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

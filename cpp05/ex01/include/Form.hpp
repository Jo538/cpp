/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 17:35:29 by admin             #+#    #+#             */
/*   Updated: 2026/10/29 10:49:22 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO: add exercises to html to know when to add namespace/scope


#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _is_signed;
	const int _grade_sign;
	const int _grade_execute;

public:
	// Constructors
	Form();
	Form(const std::string name, const int grade_sign, const int grade_execute);
	Form(const Form& other);

	// Destructor
	~Form();

	// Copy Assignment Operator Overload
	const Form& operator=(const Form& other);

	// Nested Classes
	class GradeTooHighException;
	class GradeTooLowException;

	// Getters and setters
	const std::string& getName() const;
	int isSigned() const;
	int getGradeSign() const;
	int getGradeExecute() const;

	// Member functions
	void beSigned(const Bureaucrat& bureaucrat);
};

class Form::GradeTooHighException : std::exception
{
public:
	const char *what() const throw();
};

class Form::GradeTooLowException : std::exception
{
public:
	const char *what() const throw();
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
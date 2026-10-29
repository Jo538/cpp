/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 17:35:29 by admin             #+#    #+#             */
/*   Updated: 2026/10/29 20:53:33 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO: add exercises to html to know when to add namespace/scope


#ifndef AForm_HPP
# define AForm_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _is_signed;
	const int _grade_sign;
	const int _grade_execute;

public:
	// Constructors
	AForm();
	AForm(const std::string name, const int grade_sign, const int grade_execute);
	AForm(const AForm& other);

	// Destructor
	virtual ~AForm();

	// Copy Assignment Operator Overload
	const AForm& operator=(const AForm& other);

	// Nested Classes
	class GradeTooHighException;
	class GradeTooLowException;
	class FormNotSigned;

	// Getters and setters
	const std::string& getName() const;
	int isSigned() const;
	int getGradeSign() const;
	int getGradeExecute() const;

	// Member functions
	void beSigned(const Bureaucrat& bureaucrat);
	void execute(Bureaucrat const & executor) const;
	virtual void action() const = 0;
};

class AForm::GradeTooHighException : public std::exception
{
public:
	const char *what() const throw();
};

class AForm::GradeTooLowException : public std::exception
{
public:
	const char *what() const throw();
};

class AForm::FormNotSigned : public std::exception
{
public:
	const char *what() const throw();
};

std::ostream& operator<<(std::ostream& os, const AForm& AForm);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 17:46:48 by admin             #+#    #+#             */
/*   Updated: 2026/10/27 17:51:21 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"

Form::Form() : _name("Default Form"), _is_signed(false), _grade_execute(1), _grade_sign(1)
{
	std::cout << "Form: Default Constructor called" << std::endl;
}

Form::Form(const Form& other) : _name(other._name), _is_signed(other._is_signed), _grade_execute(other._grade_execute), _grade_sign(other._grade_sign)
{
	std::cout << "Form: Copy Constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form: Destructor called" << std::endl;
}
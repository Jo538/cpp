/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationAForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 12:02:04 by admin             #+#    #+#             */
/*   Updated: 2026/10/29 12:27:56 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include <string>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	static int fail;
	const std::string _target;
	static const int _GRADE_SIGN = 72;
	static const int _GRADE_EXEC = 45;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	
	~RobotomyRequestForm();

	const RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	
	// Member functions
	void action() const;
};

#endif
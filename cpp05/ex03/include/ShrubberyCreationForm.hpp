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

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include <string>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	const std::string _target;
	static const int _GRADE_SIGN = 145;
	static const int _GRADE_EXEC = 137;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	
	~ShrubberyCreationForm();

	const ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	
	// Member functions
	void action() const;
};

#endif
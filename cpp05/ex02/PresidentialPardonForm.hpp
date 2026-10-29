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

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include <string>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	const std::string _target;
	static const int _GRADE_SIGN = 25;
	static const int _GRADE_EXEC = 5;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	
	~PresidentialPardonForm();

	const PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	
	// Member functions
	void action() const;
};

#endif
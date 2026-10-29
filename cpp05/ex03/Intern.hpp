/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 20:03:46 by admin             #+#    #+#             */
/*   Updated: 2026/10/29 20:41:26 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <exception>

class AForm;

class Intern
{
public:
	Intern();
	Intern(const Intern& other);
	
	~Intern();

	const Intern& operator=(const Intern& other);

	AForm *makeForm(const std::string& form_name, const std::string& form_target);
	
	class InexistantForm;
};

class Intern::InexistantForm: public std::exception
{
public:
	const char *what() const throw();
};
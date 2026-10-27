/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 17:35:29 by admin             #+#    #+#             */
/*   Updated: 2026/10/27 17:46:39 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Form
{
private:
	std::string _name;
	bool _is_signed;
	const int _grade_sign;
	const int _grade_execute;

public:
	// Constructors
	Form();
	Form(const Form& other);

	// Destructor
	~Form();

	// Copy Assignment Operator Overload
	const Form& operator=(const Form& other);
};
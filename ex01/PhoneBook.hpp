/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 19:39:28 by admin             #+#    #+#             */
/*   Updated: 2026/07/27 19:39:36 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
	int index;
	int fills;
	static const int MAX_COUNT = 8;
	static const int COL_WIDTH = 10;
	Contact contact[MAX_COUNT];
	void update_fills();
public:
	PhoneBook();
	bool add_contact();
	void print();
	void print_contact();
};

#endif
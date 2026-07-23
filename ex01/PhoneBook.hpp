#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>

class PhoneBook
{
 private:
	int index;
	int fills;
	static const int MAX_COUNT = 8;
	Contact contact[MAX_COUNT];
	void update_index();
	void update_fills();
 public:
	PhoneBook();
	void add_contact();
	void print();
	void print_contact();
};

#endif
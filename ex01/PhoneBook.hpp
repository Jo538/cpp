#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
 private:
	static const int MAX_COUNT = 8;
	int index;
	Contact contact[MAX_COUNT];
	void update_index();
 public:
	PhoneBook();
	void add_contact();	
};

#endif
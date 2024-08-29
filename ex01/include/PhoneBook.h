#ifndef PHONEBOOK_H
#define PHONEBOOK_H

# include <iostream>
# include <iomanip>
# include "Contact.h"

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();
	
	void	addNewContact();
	void	searchContact() const;
	void	exitPhoneBook();

private:
	static const int	max_contact = 8;
	Contact				contacts[max_contact];
	int					contact_count;
	static void 		showAllContacts();
	static void 		showContactDetails(int index);
};

#endif

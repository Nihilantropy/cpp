#ifndef PHONEBOOK_H
#define PHONEBOOK_H

# include <iostream>
# include <string>
# include <iomanip>
# include "Contact.h"

class PhoneBook
{
public:
	/*** constructor ***/
	PhoneBook();
	/*** copy constructor ***/
	PhoneBook( const PhoneBook& other );
	/*** assignment operator ***/
	PhoneBook& operator=(const PhoneBook& other );
	/*** destructor ***/
	~PhoneBook();
	
	/*** public methods ***/
	void	addNewContact( void );
	void	searchContact( void );
	void	exitPhoneBook( void );

private:
	static const int	_max_contact = 8;
	Contact				_contacts[_max_contact];
	int					_contact_count;

	/*** private methods ***/
	void 				showAllContacts() const;
	void 				showContactDetails(int index) const;
};

#endif

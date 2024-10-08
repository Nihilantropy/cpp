#include "PhoneBook.h"

/*** constructor ***/
PhoneBook::PhoneBook() : _contact_count(0) {}

/*** copy constructor ***/
PhoneBook::PhoneBook( const PhoneBook& other )
{
	this->_contact_count = other._contact_count;
	this->_contact_count = other._contact_count;
}

/*** assignment operator ***/
PhoneBook& PhoneBook::operator=( const PhoneBook& other )
{
	if (this != &other)
	{
		this->_contact_count = other._contact_count;
		this->_contact_count = other._contact_count;
	}
	return *this;
}

/*** Destructor ***/
PhoneBook::~PhoneBook() {}

/*** public methods ***/

/*	addNewContact
**	Prompts the user to enter details for a new contact, validates input,
**	and adds the contact to the phone book.
**	- If the phone book has space (less than 8 contacts), the new contact
**		is added to the next available slot.
**	- If the phone book is full, the oldest contact (index 0) is removed,
**		and the new contact is added to the end of the array. The entire array
**		is shifted to the left to make room for the new contact.
*/
void	PhoneBook::addNewContact( void )
{
	std::string	firstName, lastName, nickname, phoneNumber, darkestSecret;

	std::cout << "Enter First Name: ";
	std::getline(std::cin >> std::ws, firstName);
	if (firstName.empty())
	{
		std::cerr << "Error: First Name cannot be empty!" << std::endl;
		return;
	}

	std::cout << "Enter Last Name: ";
	std::getline(std::cin >> std::ws, lastName);
	if (lastName.empty())
	{
		std::cerr << "Error: Last Name cannot be empty!" << std::endl;
		return;
	}

	std::cout << "Enter Nickname: ";
	std::getline(std::cin >> std::ws, nickname);
	if (nickname.empty())
	{
		std::cerr << "Error: Nickname cannot be empty!" << std::endl;
		return;
	}

	std::cout << "Enter Phone Number: ";
	std::getline(std::cin >> std::ws, phoneNumber);
	if (phoneNumber.empty())
	{
		std::cerr << "Error: Phone Number cannot be empty!" << std::endl;
		return;
	}

	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin >> std::ws, darkestSecret);
	if (darkestSecret.empty())
	{
		std::cerr << "Error: Darkest Secret cannot be empty!" << std::endl;
		return;
	}

	Contact newContact(firstName, lastName, nickname, phoneNumber, darkestSecret);

	if (_contact_count < _max_contact)
	{
		_contacts[_contact_count] = newContact;
		_contact_count++;
	}
	else
	{
		for (int i = 0; i < (_max_contact - 1); i++)
			_contacts[i] = _contacts[i + 1];
		_contacts[_max_contact - 1] = newContact;
	}
}

# include <iostream>
# include <string>
# include <stdlib.h>

/*	searchContact
**	- Show the list of all contacts in the phone book, then prompt the user
**	- Ask the user to enter the index of the contact they want to display
**	- If the input is invalid, display an error message and return
**	- If the input is valid, display the details of the contact at the given index
*/
void	PhoneBook::searchContact( void )
{
	showAllContacts();

	std::string	input;

	std::cout << "Enter the index of the contact to display: ";
	std::getline(std::cin >> std::ws, input);

	int	index = atoi((input.c_str()));
	if (std::cin.fail() || index < 1 || index > _contact_count)
	{
		std::cerr << "Invalid index." << std::endl;
		return ;
	}

	showContactDetails(index);
}

/*	showAllContacts
**	Displays a table of all saved contacts with their index, first name,
**	last name, and nickname. The table has columns that are 10 characters wide,
**	with text right-aligned. If a field's content is longer than the column width,
**	it is truncated and followed by a dot. The index is displayed starting from 1.
*/
void	PhoneBook::showAllContacts( void ) const
{
	std::cout << std::setw(10) << std::right << "Index" << " | "
			  << std::setw(10) << std::right << "First Name" << " | "
			  << std::setw(10) << std::right << "Last Name" << " | "
			  << std::setw(10) << std::right << "Nickname" << std::endl;
	std::cout << "----------|------------|------------|------------" << std::endl;

	for (int i = 0; i < _contact_count; ++i)
	{
		std::cout << std::setw(10) << std::right << (i + 1) << " | "
				  << std::setw(10) << std::right << (_contacts[i].getFirstName().substr(0, 9) + (_contacts[i].getFirstName().length() > 10 ? "." : "")) << " | "
				  << std::setw(10) << std::right << (_contacts[i].getLastName().substr(0, 9) + (_contacts[i].getLastName().length() > 10 ? "." : "")) << " | "
				  << std::setw(10) << std::right << (_contacts[i].getNickname().substr(0, 9) + (_contacts[i].getNickname().length() > 10 ? "." : "")) << std::endl;
	}
}

/*	showContactDetails
**	Displays the details of a contact at the specified index.
**	- Outputs the contact's first name, last name, nickname,
**		phone number, and darkest secret, each on a new line.
*/
void	PhoneBook::showContactDetails(int index) const
{
	const Contact& contact = _contacts[--index];
	
	std::cout << "First Name: " << contact.getFirstName() << std::endl
			  << "Last Name: " << contact.getLastName() << std::endl
			  << "Nickname: " << contact.getNickname() << std::endl
			  << "Phone Number: " << contact.getPhoneNumber() << std::endl
			  << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}

/*	exitPhoneBook
**	Displays a farewell message and terminates the phone book program.
**	This function is called when the user chooses to exit the program.
*/
void	PhoneBook::exitPhoneBook()
{
	std::cout << "Exiting phone book. Goodbye!" << std::endl;
}

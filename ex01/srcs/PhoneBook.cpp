#include "../include/PhoneBook.h"

/*	Constructor implementation
		Initialize contact_count to 0
*/
PhoneBook::PhoneBook() : contact_count(0) {}

/*	addNewContact
		Prompts the user to enter details for a new contact, validates input,
		and adds the contact to the phone book.
		- If the phone book has space (less than 8 contacts), the new contact
		  is added to the next available slot.
		- If the phone book is full, the oldest contact (index 0) is removed,
		  and the new contact is added to the end of the array. The entire array
		  is shifted to the left to make room for the new contact.
*/
void	PhoneBook::addNewContact()
{
	std::string	firstName, lastName, nickname, phoneNumber, darkestSecret;

	std::cout << "Enter First Name: ";
	std::cin.ignore();
	std::getline(std::cin, firstName);
	std::cout << "Enter Last Name: ";
	std::getline(std::cin, lastName);
	std::cout << "Enter Nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin, darkestSecret);

	if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty())
	{
		std::cerr << "Contact can't have empty fields!" << std::endl;
		return;
	}

	Contact newContact(firstName, lastName, nickname, phoneNumber, darkestSecret);

	if (contact_count < max_contact)
	{
		contacts[contact_count] = newContact;
		contact_count++;
	}
	else
	{
		for (int i = 0; i < (max_contact - 1); i++)
			contacts[i] = contacts[i + 1];
		contacts[max_contact - 1] = newContact;
	}
}

/*	searchContact
		- Show the list of all contacts in the phone book, then prompt the user
		- Ask the user to enter the index of the contact they want to display
		- If the input is invalid, display an error message and return
		- If the input is valid, display the details of the contact at the given index
*/
void	PhoneBook::searchContact() const
{
	showAllContacts();

	int index;

	std::cout << "Enter the index of the contact to display: ";
	std::cin >> index;

	if (std::cin.fail() || index < 0 || index >= contact_count)
	{
		std::cout << "Invalid index." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}

	showContactDetails(index);
}

/*	showAllContacts
		Displays a table of all saved contacts with their index, first name,
		last name, and nickname. The table has columns that are 10 characters wide,
		with text right-aligned. If a field's content is longer than the column width,
		it is truncated and followed by a dot. The index is displayed starting from 1.
*/
void	PhoneBook::showAllContacts() const
{
	std::cout << std::setw(10) << std::right << "Index" << " | "
			  << std::setw(10) << std::right << "First Name" << " | "
			  << std::setw(10) << std::right << "Last Name" << " | "
			  << std::setw(10) << std::right << "Nickname" << std::endl;
	std::cout << "----------|------------|------------|------------" << std::endl;

	for (int i = 0; i < contact_count; ++i)
	{
		std::cout << std::setw(10) << std::right << (i + 1) << " | "
				  << std::setw(10) << std::right << (contacts[i].getFirstName().substr(0, 9) + (contacts[i].getFirstName().length() > 10 ? "." : "")) << " | "
				  << std::setw(10) << std::right << (contacts[i].getLastName().substr(0, 9) + (contacts[i].getLastName().length() > 10 ? "." : "")) << " | "
				  << std::setw(10) << std::right << (contacts[i].getNickname().substr(0, 9) + (contacts[i].getNickname().length() > 10 ? "." : "")) << std::endl;
	}
}

/*	showContactDetails
		Displays the details of a contact at the specified index.
		- Outputs the contact's first name, last name, nickname,
		  phone number, and darkest secret, each on a new line.
*/
void	PhoneBook::showContactDetails(int index) const
{
	const Contact& contact = contacts[index];
	std::cout << "First Name: " << contact.getFirstName() << std::endl
			  << "Last Name: " << contact.getLastName() << std::endl
			  << "Nickname: " << contact.getNickname() << std::endl
			  << "Phone Number: " << contact.getPhoneNumber() << std::endl
			  << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}

/*	exitPhoneBook
		Displays a farewell message and terminates the phone book program.
		This function is called when the user chooses to exit the program.
*/
void	PhoneBook::exitPhoneBook()
{
	std::cout << "Exiting phone book. Goodbye!" << std::endl;
}

/*	Destructor implementation
		No dynamic memory allocation, so no need to delete anything
*/
PhoneBook::~PhoneBook() {}

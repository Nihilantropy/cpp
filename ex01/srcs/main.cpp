#include <iostream>
#include "PhoneBook.h"

/*	main
		The entry point of the program that handles user interaction and
		commands for the phone book. It continuously prompts the user to
		enter a command and processes it:
		- "ADD" invokes the addNewContact method to add a new contact.
		- "SEARCH" invokes the searchContact method to display contacts.
		- "EXIT" invokes the exitPhoneBook method to terminate the program.
		If an invalid command is entered, an error message is displayed.
*/
int main()
{
	PhoneBook	phoneBook;
	std::string	command;

	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::cin >> command;

		if (command == "ADD")
		{
			phoneBook.addNewContact();
		}
		else if (command == "SEARCH")
		{
			phoneBook.searchContact();
		}
		else if (command == "EXIT")
		{
			phoneBook.exitPhoneBook();
			break ;
		}
		else
		{
			std::cout << "Invalid command. Please try again." << std::endl;
		}
	}

	return (0);
}

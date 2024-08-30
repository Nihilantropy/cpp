#include "PhoneBook.h"

static int	commandToOption( std::string& command );

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

		switch (commandToOption(command))
		{
			case 1:
				phoneBook.addNewContact();
				break ;
			case 2:
				phoneBook.searchContact();
				break ;
			case 3:
				phoneBook.exitPhoneBook();
				return 0;

			default:
				std::cout << "Invalid command. Please try again." << std::endl;
				break ;
		}
	}

	return (0);
}

static int	commandToOption( std::string& command )
{
	if (command == "ADD")
		return 1;
	else if (command == "SEARCH")
		return 2;
	else if (command == "EXIT")
		return 3;
	else
		return 0;
}

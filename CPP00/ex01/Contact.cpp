#include "Contact.h"

/*	Costructor implementation
**	Initialize all member variables with empty string
 */
Contact::Contact() :	first_name(""),
						last_name (""),
						nickname(""),
						phone_number(""),
						darkest_secret("") {}

/*	Parameterized constructor implementation
**	Initialize all member variables with the given parameters
*/
Contact::Contact(const std::string& first_name,
					const std::string& last_name,
					const std::string& nickname,
					const std::string& phone_number,
					const std::string& darkest_secret) :
					first_name(first_name),
					last_name(last_name),
					nickname(nickname),
					phone_number(phone_number),
					darkest_secret(darkest_secret) {}

/*	Getter functions implementation
**	Return the value of the member variables
*/
std::string Contact::getFirstName() const
{
	return first_name;
}

std::string Contact::getLastName() const
{
	return last_name;
}

std::string Contact::getNickname() const
{
	return nickname;
}

std::string Contact::getPhoneNumber() const
{
	return phone_number;
}

std::string Contact::getDarkestSecret() const
{
	return darkest_secret;
}

/*	Destructor implementation
**	No dynamic memory allocation, so no need to delete anything
*/
Contact::~Contact() {}

#ifndef CONTACT_H
#define CONTACT_H

# include <string>

class Contact
{
public:
	Contact();
	Contact(const std::string& first_name, const std::string& last_name,
			const std::string& nickname, const std::string& phone_number,
			const std::string& darkest_secret);
	std::string	getFirstName() const;
	std::string	getLastName() const;
	std::string	getNickname() const;
	std::string getPhoneNumber() const;
	std::string	getDarkestSecret() const;
	~Contact();

private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
};

#endif

#include "Contact.h"

Contact::Contact() :	_first_name(""),
						_last_name(""),
						_nickname(""),
						_phone_number(""),
						_darkest_secret("") {}

/*** costructor ***/
Contact::Contact(const std::string& first_name,
					const std::string& last_name,
					const std::string& nickname,
					const std::string& phone_number,
					const std::string& darkest_secret) :
					_first_name(first_name),
					_last_name(last_name),
					_nickname(nickname),
					_phone_number(phone_number),
					_darkest_secret(darkest_secret) {}

/*** copy costructor ***/
Contact::Contact( const Contact& other )
{
	this->_first_name = other._first_name;
	this->_last_name = other._last_name;
	this->_nickname = other._nickname;
	this->_phone_number = other._phone_number;
	this->_darkest_secret = other._darkest_secret;
}

/*** assignment operator ***/
Contact&	Contact::operator=( const Contact& other )
{
	if (this != &other )
	{
		this->_first_name = other._first_name;
		this->_last_name = other._last_name;
		this->_nickname = other._nickname;
		this->_phone_number = other._phone_number;
		this->_darkest_secret = other._darkest_secret;
	}
	return *this;
}

/*** destructor ***/
Contact::~Contact() {}

/*** getters ***/
const std::string Contact::getFirstName( void ) const
{
	return _first_name;
}

const std::string Contact::getLastName( void ) const
{
	return _last_name;
}

const std::string Contact::getNickname( void ) const
{
	return _nickname;
}

const std::string Contact::getPhoneNumber( void ) const
{
	return _phone_number;
}

const std::string Contact::getDarkestSecret( void ) const
{
	return _darkest_secret;
}

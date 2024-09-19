#include "Intern.h"

/***  Costructor ***/
Intern::Intern() {}

/***  Copy costructor ***/
Intern::Intern( const Intern& other ) { *this = other; }

/***  assignment operator override ***/
Intern& Intern::operator=( const Intern& other )
{
	if (this != &other)
	{
		// Assignment operator implementation
	}
	return *this;
}

/***  Destructor ***/
Intern::~Intern() {}

/*** public methods ***/
/* array of pointers to member functions */
Form* Intern::makeForm(const std::string& name, const std::string& target)
{
	for (size_t i = 0; i < sizeof(formMappings) / sizeof(formMappings[0]); ++i)
	{
		if (name == formMappings[i]._name)
			return (this->*(formMappings[i]._creator))(target);
	}
	throw FormNameException();
}

/*** private methods ***/
/*	
**	form mapping implementation 
**	to pair the name of the form with
**	the corrisponding 'createForm' function
*/
const	Intern::FormMapping Intern::formMappings[] = {
	{"robotomy request", &Intern::createRobotomyRequest},
	{"shrubbery creation", &Intern::createShrubberyCreation},
	{"presidential pardon", &Intern::createPresidentialPardon}
};

/* static function for form creation */
Form*	Intern::createRobotomyRequest(const std::string& target) {
		return new RobotomyRequestForm(target);
}

Form*	Intern::createShrubberyCreation(const std::string& target) {
		return new ShrubberyCreationForm(target);
}

Form*	Intern::createPresidentialPardon(const std::string& target) {
		return new PresidentialPardonForm(target);
}

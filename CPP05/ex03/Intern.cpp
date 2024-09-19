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
Form* Intern::makeForm(const std::string& name, const std::string& target)
{
    for (size_t i = 0; i < sizeof(formCreators) / sizeof(formCreators[0]); ++i)
    {
        if (std::strcmp(formCreators[i].first, name.c_str()) == 0)
        {
            std::cout << "Intern creates " << name << std::endl;
            return (this->*(formCreators[i].second))(target);
        }
    }
    throw FormNameException();
}

/*** private methods ***/
/* static function for form creation */
Form*	Intern::createRobotomyRequest(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

Form*	Intern::createShrubberyCreation(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

Form*	Intern::createPresidentialPardon(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

/* array of pointers to member functions */
const std::pair<std::string, Intern::FormCreator> Intern::formCreators[] = {
    {"robotomy request", Intern::createRobotomyRequest},
    {"shrubbery creation", Intern::createShrubberyCreation},
    {"presidential pardon", Intern::createPresidentialPardon}
};

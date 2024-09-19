#ifndef INTERN_H
#define INTERN_H

# include "AForm.h"
# include <utility>

class Intern
{
public:
	/*** costructor ***/
	Intern();
	/*** copy costructor ***/
	Intern( const Intern& other );
	/*** assignment operator ***/
	Intern& operator=( const Intern& other );
	/*** destructor ***/
	~Intern();

	/*** public methods ***/
	Form*	makeForm( const std::string& name, const std::string& target );

	class FormNameException : public std::exception
	{
	public:
		/*** public methods ***/
		const char*	what() const throw()
		{
			return "Form name provided is incorrect.";
		}
	};
private:
	/*** private methods ***/
	/* static function for form creation */
	static Form* createRobotomyRequest(const std::string& target);
	static Form* createShrubberyCreation(const std::string& target);
	static Form* createPresidentialPardon(const std::string& target);

	/* array of pointers to member functions */
	typedef Form* (Intern::*FormCreator)(const std::string&) const;
	/* pairing the form name with the corrisponding 'createForm' function */
	struct FormMapping
	{
		const char* _name;
		FormCreator _creator;
	};

	static const FormMapping	formMappings[];
};

#endif

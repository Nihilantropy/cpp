#ifndef PRESIDENTIAL_PARDON_FORM_H
#define PRESIDENTIAL_PARDON_FORM_H

# include "Form.h"

class PresidentialPardonForm : public Form
{
public:
	/* costructor with target */
	PresidentialPardonForm( const std::string& target );
	/* copy costructor */
	PresidentialPardonForm( const PresidentialPardonForm& other );
	/* assignment operator */
	PresidentialPardonForm& operator=( const PresidentialPardonForm& other );
	/* destructor */
	~PresidentialPardonForm();

	/* public methods */
	void	execute( const Bureaucrat& executor ) const;

private:
	std::string	_target;
};

#endif
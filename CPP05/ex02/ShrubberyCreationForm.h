#ifndef SHRUBERRY_CREATION_FORM_H
#define SHRUBERRY_CREATION_FORM_H

# include "Form.h"

class  ShrubberyCreationForm : public Form
{
public:
	/* costructor with target */
	ShrubberyCreationForm( const std::string& target );
	/* copy costructor */
	ShrubberyCreationForm( const ShrubberyCreationForm& other );
	/* assignment operator */
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other );
	/* destructor */
	~ShrubberyCreationForm();

	/* public method override */
	void	execute( const Bureaucrat& executor ) const;

	class FileOpeningException : public std::exception
	{
	public:
		/* public methods */
		const char*	what() const throw()
		{
			return "Error: could not create the shrubbery file.";
		}
	};

private:
	std::string	_target;
};

#endif
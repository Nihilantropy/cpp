#ifndef ROBOMY_REQUEST_FORM_H
#define ROBOMY_REQUEST_FORM_H

# include "AForm.h"
# include <cstdlib>

class RobotomyRequestForm : public AForm
{
public:
	/* costructor with target */
	RobotomyRequestForm( const std::string& target );
	/* copy costructor */
	RobotomyRequestForm( const RobotomyRequestForm& other );
	/* assignment operator */
	RobotomyRequestForm& operator=( const RobotomyRequestForm& other );
	/* destructor */
	~RobotomyRequestForm();

	/* public methods */
	void	execute( const Bureaucrat& executor ) const;

private:
	std::string	_target;
};

#endif
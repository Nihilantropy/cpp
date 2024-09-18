#ifndef FORM_H
#define FORM_H

# include <iostream>
# include <string>
# include <stdexcept>
# include "Bureaucrat.h"

class Bureaucrat;

class Form
{
public:
	/* costructor */
	Form( const std::string& name, const int gradeToSign, const int grade_toExec );
	/* copy costructor */
	Form( const Form& other );
	/* assignment operator */
	Form& operator= ( const Form& other );
	/* destructor */
	~Form();

	/* getters */
	const std::string&	getName() const;
	bool				getIsSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExec() const;

	/* public methods */
	void				beSigned( const Bureaucrat& bureaucrat );

	/* exception class with what() method override */
	class GradeTooHighException : public std::exception
	{
	public:
		/* public methods */
		const char*	what() const throw()
		{
			return "Grade too high!";
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		/* public methods */
		const char*	what() const throw()
		{
			return "Grade too low!";
		}
	};
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExec;

	void				checkGrade( int grade ) const ;
};

std::ostream& operator<<( std::ostream& os, const Form& form );

#endif
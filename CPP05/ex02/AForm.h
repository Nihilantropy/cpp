#ifndef AFORM_H
#define AFORM_H

# include <iostream>
# include <string>
# include <stdexcept>
# include <fstream>
# include "Bureaucrat.h"

class Bureaucrat;

class AForm
{
public:
	/* costructor */
	AForm( const std::string& name, const int gradeToSign, const int grade_toExec );
	/* copy costructor */
	AForm( const AForm& other );
	/* assignment operator */
	AForm& operator=( const AForm& other );
	/* destructor */
	virtual ~AForm();

	/* getters */
	const std::string&	getName() const;
	bool				getIsSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExec() const;

	/* public methods */
	void				beSigned( const Bureaucrat& bureaucrat );

	/* pure virutal method */
	virtual void		execute( const Bureaucrat& executor ) const = 0;

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

	class FormNotSignedException : public std::exception
	{
	public:
		/* public methods */
		const char*	what() const throw()
		{
			return "Form is not signed!";
		}
	};

private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExec;

	void				checkGrade( int grade ) const ;
};

std::ostream& operator<<( std::ostream& os, const AForm& form );

#endif
#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

# include <iostream>
# include <string>
# include <stdexcept>
# include "Form.h"

class Form;

class Bureaucrat
{
public:
	/*** costructor ***/
	Bureaucrat( const std::string& name, int grade );
	/*** copy costructor ***/
	Bureaucrat( const Bureaucrat& other );
	/*** assignment operator ***/
	Bureaucrat& operator= ( const Bureaucrat& other );
	/*** destructor ***/
	~Bureaucrat();

	/*** getter ***/
	const std::string&	getName( void ) const;
	int					getGrade( void ) const;

	/*** public methods ***/
	void			incrementGrade();
	void			decrementGrade();
	void			signForm( Form& form ) const;

	/*** exception class with what() method override ***/
	class	GradeTooHighException : public std::exception
	{
	public:
		/*** public methods ***/
		const char*	what() const throw()
		{
			return "Bureaucrat grade too high!";
		}
	};

	class	GradeTooLowException : public std::exception
	{
	public:
		const char*	what() const throw()
		{
			return "Bureaucrat grade too low!";
		}
	};

private:
	const std::string	_name;
	int					_grade;
	void				checkGrade( int grade ) const ;
};

std::ostream& operator<<( std::ostream& os, const Bureaucrat& bureaucrat );

#endif

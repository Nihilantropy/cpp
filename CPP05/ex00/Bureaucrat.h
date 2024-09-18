#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

# include <iostream>
# include <string>
# include <stdexcept>

class Bureaucrat
{
public:
	/* costructor & destructor */
	Bureaucrat( const std::string& name, int grade );
	Bureaucrat( const Bureaucrat& other );
	Bureaucrat& operator= ( const Bureaucrat& other );
	~Bureaucrat();

	/* getter */
	int					getGrade( void ) const;
	const std::string&	getName( void ) const;
	
	/* setter */
	void			setGrade( int grade );

	/* public methods */
	void			incrementGrade();
	void			decrementGrade();

	/* exception class with what() method override */
	class	GradeTooHighException : public std::exception
	{
	public:
		/* public methods */
		const char*	what() const throw()
		{
			return "Grade too high!";
		}
	};

	class	GradeTooLowException : public std::exception
	{
	public:
		const char*	what() const throw()
		{
			return "Grade too low!";
		}
	};

private:
	const std::string	_name;
	int					_grade;
	void				checkGrade( int grade );
};

std::ostream& operator<<( std::ostream& os, const Bureaucrat& bureaucrat );

#endif

#include "Bureaucrat.h"

/* costructor */
Bureaucrat::Bureaucrat( const std::string& name, int grade ) : _name(name), _grade(grade)
{
	checkGrade(_grade);
}

/* copy costructor */
Bureaucrat::Bureaucrat( const Bureaucrat& other ) : _name(other._name), _grade(other._grade) {}

/* assignament operator */
Bureaucrat&	Bureaucrat::operator=( const Bureaucrat& other )
{
	if (this != &other)
		this->_grade = other._grade;
	return *this;
}

/* destructor */
Bureaucrat::~Bureaucrat() {}

/* getter */
const std::string&	Bureaucrat::getName( void ) const { return _name; }
int					Bureaucrat::getGrade( void ) const { return _grade; }

/* setter */
void	Bureaucrat::setGrade( int grade ) { _grade = grade; }

/* public methods */
void	Bureaucrat::incrementGrade()
{
	checkGrade(_grade - 1);
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	checkGrade(_grade + 1);
	_grade++;
}

void	Bureaucrat::checkGrade( int grade )
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

/* << operator overload */
std::ostream& operator<<( std::ostream& os, const Bureaucrat& bureaucrat )
{
	os << bureaucrat.getName() << ", bureaucrat grade is: " << bureaucrat.getGrade() << std::endl;
	return os;
}
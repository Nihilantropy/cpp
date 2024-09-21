#include "Form.h"

/*** constructor ***/
Form::Form( const std::string& name, const int gradeToSign, const int gradeToExec)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	checkGrade(gradeToSign);
	checkGrade(gradeToExec);
}

/*** copy constructor ***/
Form::Form( const Form& other )
	: _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {}

/*** assignment operator ***/
Form&	Form::operator=( const Form& other )
{
	if (this != &other )
	{
		_isSigned = other._isSigned;
	}
	return *this;
}

/*** destructor ***/
Form::~Form() {}

/*** getters ***/
const std::string&	Form::getName() const { return _name; }
bool				Form::getIfSigned() const { return _isSigned; }
int					Form::getGradeToSign() const { return _gradeToSign; }
int					Form::getGradeToExec() const { return _gradeToExec; }

/*** public methods ***/
void				Form::beSigned( const Bureaucrat& bureaucrat )
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

/*** private methods ***/
void	Form::checkGrade( int grade ) const
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

/*** '<<' operator overload ***/
std::ostream& operator<<( std::ostream& os, const Form& form )
{
	os << "Form " << form.getName() << ", signed: " << (form.getIfSigned() ? "yes" : "no")
	   << ", grade required to sign: " << form.getGradeToSign()
	   << ", grade required to execute: " << form.getGradeToExec();
	return os;
}

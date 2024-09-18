#include "AForm.h"

/* costructor */
AForm::AForm( const std::string& name, const int gradeToSign, const int gradeToExec)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	checkGrade(gradeToSign);
	checkGrade(gradeToExec);
}

/* copy costructor */
AForm::AForm( const AForm& other )
	: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {}

/* assignment operator */
AForm&	AForm::operator=( const AForm& other )
{
	if (this != &other )
	{
		_isSigned = other._isSigned;
	}
	return *this;
}

/* destructor */
AForm::~AForm() {}

/* getters */
const std::string&	AForm::getName() const { return _name; }
bool				AForm::getIsSigned() const { return _isSigned; }
int					AForm::getGradeToSign() const { return _gradeToSign; }
int					AForm::getGradeToExec() const { return _gradeToExec; }

/* public methods */
void				AForm::beSigned( const Bureaucrat& bureaucrat )
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

/* private methods */
void	AForm::checkGrade( int grade ) const
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

/* overload of the << operator */
std::ostream& operator<<( std::ostream& os, const AForm& form )
{
	os << "AForm " << form.getName() << ", signed: " << (form.getIsSigned() ? "yes" : "no")
	   << ", grade required to sign: " << form.getGradeToSign()
	   << ", grade required to execute: " << form.getGradeToExec();
	return os;
}

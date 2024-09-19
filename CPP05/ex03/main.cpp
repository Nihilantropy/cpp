#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

int main()
{
	try
	{
		/* Test ShrubberyCreationForm */
		Bureaucrat				bob("Bob", 140);
		ShrubberyCreationForm	form("Home");

		std::cout << form << std::endl;

		bob.signForm(form);
		bob.executeForm(form);

		std::cout << form << std::endl;

		Bureaucrat				alice("Alice", 2);
		ShrubberyCreationForm	form2("Gym");

		std::cout << alice << std::endl;
		alice.incrementGrade();

		std::cout << alice << std::endl;
		alice.signForm(form2);
		alice.executeForm(form2);

		std::cout << form2 << std::endl;

		std::cout << std::endl;

		/* Test RobotomyRequestForm */
		Bureaucrat				charles("Charles", 45);
		RobotomyRequestForm		form3("Target");

		std::cout << form3 << std::endl;
		std::cout << charles << std::endl;

		/* Charles tries to sign and execute the form */
		charles.signForm(form3);
		charles.executeForm(form3);

		std::cout << form3 << std::endl;

		/* Test with a higher grade Bureaucrat */
		Bureaucrat				diana("Diana", 1);
		RobotomyRequestForm		form4("Another Target");

		std::cout << diana << std::endl;
		diana.signForm(form4);
		diana.executeForm(form4);

		std::cout << form4 << std::endl;

		std::cout << std::endl;

		Bureaucrat				apollo("Apollo", 6);
		PresidentialPardonForm	form5("Target");

		std::cout << apollo << std::endl;

		apollo.signForm(form5);
		apollo.executeForm(form5);

		std::cout << form5 << std::endl;

		apollo.incrementGrade();
		std::cout << apollo << std::endl;

		apollo.executeForm(form5);

		std::cout << std::endl;

	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
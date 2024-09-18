#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"

int main()
{
    try
    {
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

    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
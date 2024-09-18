#include <iostream>
#include "Bureaucrat.h"
#include "Form.h"

int main()
{
    try {
        // Test: Bureaucrat with a valid grade
        Bureaucrat john("John", 50);
        std::cout << john << std::endl;

        // Test: Bureaucrat grade too high
        try {
            Bureaucrat jane("Jane", 0); // Should throw GradeTooHighException
        } catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        // Test: Bureaucrat grade too low
        try {
            Bureaucrat bob("Bob", 200); // Should throw GradeTooLowException
        } catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        // Test: Form creation with valid grades
        Form taxForm("Tax Form", 30, 40);
        std::cout << taxForm << std::endl;

        // Test: Form creation with grade too high
        try {
            Form invalidForm("Invalid Form", 0, 40); // Should throw GradeTooHighException
        } catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        // Test: Form creation with grade too low
        try {
            Form anotherInvalidForm("Another Invalid Form", 151, 140); // Should throw GradeTooLowException
        } catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        // Test: Signing a form
        Bureaucrat alice("Alice", 25);
        Form passportForm("Passport Form", 30, 20);
        alice.signForm(passportForm); // Alice should sign the form
        std::cout << passportForm << std::endl;

        // Test: Bureaucrat signing a form with insufficient grade
        try {
            Bureaucrat charles("Charles", 50);
            Form visaForm("Visa Form", 20, 10);
            charles.signForm(visaForm); // Charles should not be able to sign
        } catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        // Test: Incrementing and decrementing grade
        john.incrementGrade();
        std::cout << "After incrementing: " << john << std::endl;
        john.decrementGrade();
        std::cout << "After decrementing: " << john << std::endl;

        // Test: Incrementing beyond limit
        try {
            Bureaucrat elite("Elite", 1);
            elite.incrementGrade(); // Should throw GradeTooHighException
        } catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        // Test: Decrementing beyond limit
        try {
            Bureaucrat newbie("Newbie", 150);
            newbie.decrementGrade(); // Should throw GradeTooLowException
        } catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cout << "Exception caught in main: " << e.what() << std::endl;
    }

    return 0;
}


#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ()
{
        Bureaucrat a;
        Bureaucrat b;
        Bureaucrat c;

        try
        {
            a = Bureaucrat("John", 50);
            std::cout << "a: " << a << std::endl;
            c = a; // a is copied to c
        } catch (const Bureaucrat::GradeTooHighException &e) {
            std::cerr << "Exception c: " << e.what() << std::endl;
        } catch (const Bureaucrat::GradeTooLowException &e) {
            std::cerr << "Exception c: " << e.what() << std::endl;
        }
        try
        {
            b = Bureaucrat("Bob", 1);
            std::cout << "b: " << b << std::endl;
        } catch (const Bureaucrat::GradeTooHighException &e) {
            std::cerr << "Exception c: " << e.what() << std::endl;
        } catch (const Bureaucrat::GradeTooLowException &e) {
            std::cerr << "Exception c: " << e.what() << std::endl;
        }

        std::cout << "a: " << a << std::endl;
        std::cout << "b: " << b << std::endl;
        std::cout << "c: " << c << std::endl;
        std::cout<< "============================" << std::endl;

        try
        {
            c.incrementGrade();
        } catch (const Bureaucrat::GradeTooHighException &e) {
            std::cerr << "Exception c: " << e.what() << std::endl;
        } catch (const Bureaucrat::GradeTooLowException &e) {
            std::cerr << "Exception c: " << e.what() << std::endl;
        }

        std::cout << "c: after increament: "<< c << std::endl;
        std::cout << "c: " << c << std::endl;
        std::cout<< "============================" << std::endl;

        try
        {
            b.decrementGrade();
        } catch (const Bureaucrat::GradeTooHighException &e) {
            std::cerr << "Exception b: " << e.what() << std::endl;
        } catch (const Bureaucrat::GradeTooLowException &e) {
            std::cerr << "Exception b: " << e.what() << std::endl; } 
        std::cout << "b: after decreament: "<< b << std::endl;
        std::cout << "b: " << b << std::endl;

        
        std::cout << "===============Init Forms ================" << std::endl;
        try {
            // this will fail
            Form form0("Form0", 1, -1);
        }catch (const Form::GradeTooHighException& e) {
            std::cerr << "Exception form0: " << e.what() << std::endl; }
        catch (const Form::GradeTooLowException& e) {
            std::cerr << "Exception form0: " << e.what() << std::endl; }
        
        std::cout << "===============================" << std::endl;

        try {
            Form form1("Form1", 50, 5);
            std::cout << "a: " << a << " | form1 grade:" << form1.getSignGrade() << std::endl;
            form1.beSigned(a);
        }catch (const Form::GradeTooHighException& e) {
            std::cerr << "Exception form1: " << e.what() << std::endl; }
        catch (const Form::GradeTooLowException& e) {
            std::cerr << "Exception form1: " << e.what() << std::endl; }

        try {
            Form form2("Form2", 70, 50);
            std::cout << "b: " << b << " | form2 grade:" << form2.getSignGrade() << std::endl;
            form2.beSigned(b);
        }catch (const Form::GradeTooHighException& e) {
            std::cerr << "Exception form2: " << e.what() << std::endl; }
        catch (const Form::GradeTooLowException& e) {
            std::cerr << "Exception form2: " << e.what() << std::endl; }


        std::cout<< "============This won't be signed ================" << std::endl;
   
        try {
            Form form3("Form3", 10, 5);
            std::cout << "c: " << c << " | form3 grade:" << form3.getSignGrade() << std::endl;
            c.signForm(form3);
        }catch (const Form::GradeTooHighException& e) {
            std::cerr << "Exception form3: " << e.what() << std::endl; }
        catch (const Form::GradeTooLowException& e) {
            std::cerr << "Exception form3: " << e.what() << std::endl; }

    return 0;
}
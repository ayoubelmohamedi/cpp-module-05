

#include "Bureaucrat.hpp"

int main ()
{
    try
    {
        Bureaucrat bureaucrat("John", 1);
        Bureaucrat c("Bob", 100);

        Bureaucrat b = bureaucrat;
        std::cout << b << std::endl;
        std::cout << bureaucrat << std::endl;
        bureaucrat.incrementGrade();
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}
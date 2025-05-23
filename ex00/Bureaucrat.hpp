


#ifndef BUREAUCRAT_CPP
#define BUREAUCRAT_CPP


#include <iostream>
#include <string>
#include <exception>


class Bureaucrat
{
    private: 
        const std::string _name;
        int _grade;
    
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
};

std::ostream &operator<<(std::ostream & os, const Bureaucrat &bureaucrat);






#endif
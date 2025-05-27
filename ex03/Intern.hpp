

#ifndef INTERN_HPP
#define INTERN_HPP


#include <iostream>
#include <string>
#include <exception>
#include <AForm.hpp>


class Intern 
{
    public:
        Intern();
        Intern(const Intern & other);
        Intern &operator=(const Intern &other);
        ~Intern();

        AForm *makeForm(const std::string _formName, const std::string target) const;
};


std::ostream &operator<<(std::ostream & os, const Intern &Intern);

#endif
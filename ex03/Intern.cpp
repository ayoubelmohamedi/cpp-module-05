/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:06:56 by ael-moha          #+#    #+#             */
/*   Updated: 2025/05/28 18:51:47 by ael-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Intern.hpp"


Intern::Intern()
{
    std::cout << "Intern Default Constructor called" << std::endl;
}
Intern::Intern(const Intern & other)
{
    std::cout << "Intern Copy Constructor called" << std::endl;
    *this = other;
}

static AForm *create_robotomy(const std::string &target) { return (new RobotomyRequestForm(target));}
static AForm *create_shrubby(const std::string &target) { return (new ShrubberyCreationForm(target));}
static AForm *create_presidential(const std::string &target) { return (new PresidentialPardonForm(target));}

// general ptr to function with name FormCreator, it takes one arg and return AForm type. 
typedef AForm* (*FormCreator) (const std::string&);

struct FormMap
{
    const char* name;
    FormCreator creator;
};

static const FormMap forms[] = {
    {"robotomy request", create_robotomy},
    {"shrubbery creation", create_shrubby},
    {"presidential pardon", create_presidential}
};

AForm* Intern::makeForm(const std::string _formName, const std::string target) const
{
    //data-driven approach, instead of if/else
    for (size_t i = 0; i < 3; i++)
    {
        if (_formName == forms[i].name)
            return (forms[i].creator(target));
    }
    return (nullptr);
} 

Intern &Intern::operator=(const Intern &other)
{
    std::cout << "Intern Assignation operator called" << std::endl;
    // nothing to copy
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern Deconstructor called" << std::endl;
}
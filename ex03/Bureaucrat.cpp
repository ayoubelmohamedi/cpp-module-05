/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:06:51 by ael-moha          #+#    #+#             */
/*   Updated: 2025/05/28 23:48:33 by ael-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
    std::cout << "Default constructor called: " << _name << ", grade " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        _grade = grade;
    std::cout << "Constructor called:" << _name << ", grade " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name)
{
    std::cout << "Copy constructor called: " << _name << ", grade " << _grade << std::endl;
    *this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Copy assignment operator called " << _name << ", grade " << _grade << std::endl;
    if (this != &other)
        _grade = other._grade;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::incrementGrade()
{
    if (_grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    if (_grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

void Bureaucrat::signForm(AForm &form) const
{
    if (form.isSigned())
    {
        std::cout << getName() << " couldn’t sign " << form.getName() << " because it is already signed." << std::endl;
    }
    else if (getGrade() > form.getSignGrade())
    {
        std::cout << getName() << " couldn’t sign " << form.getName() << " because their grade is too low." << std::endl;
    }
    else
    {
        form.beSigned(*this);
    }
}

void Bureaucrat::executeForm(const AForm &form) const
{
    if (!form.isSigned())
        throw AForm::FormNotSignedException();
    if (!form.isExecutableBy(*this))
        throw AForm::GradeTooLowException();
    form.execute(*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}









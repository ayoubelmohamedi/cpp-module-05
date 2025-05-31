/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:08:18 by ael-moha          #+#    #+#             */
/*   Updated: 2025/05/27 22:08:19 by ael-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Form.hpp"



Form::Form() : _name("default_form"), _isSigned(false), _signGrade(150), _executeGrade(150)
{
    std::cout << "Default constructor called: " << _name << ", sign grade " << _signGrade << ", execute grade " << _executeGrade << std::endl;
}

Form::Form(const std::string name, int signGrade, int executeGrade) 
    : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw Form::GradeTooHighException();
    else if (signGrade > 150 || executeGrade > 150)
        throw Form::GradeTooLowException();
    std::cout << "Constructor called: " << _name << ", sign grade " << _signGrade << ", execute grade " << _executeGrade << std::endl;
}

Form::Form(const Form &other) 
    : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
    std::cout << "Copy constructor called: " << _name << ", sign grade " << _signGrade << ", execute grade " << _executeGrade << std::endl;
}

Form &Form::operator=(const Form &other)
{
    std::cout << "Copy assignment operator called: " << _name << ", sign grade " << _signGrade << ", execute grade " << _executeGrade << std::endl;
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

Form::~Form()
{
    std::cout << "Destructor called for form: " << _name << std::endl;
}

std::string Form::getName() const
{
    return _name;
}

bool Form::isSigned() const
{
    return _isSigned;
}

int Form::getSignGrade() const
{
    return _signGrade;
}

int Form::getExecuteGrade() const
{
    return _executeGrade;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (isSigned())
    {
        std::cout << bureaucrat.getName() << " couldn’t sign " <<_name << ", because it's already signed." << std::endl;
        return;
    }
    if (bureaucrat.getGrade() > _signGrade)
    {
        std::cout << bureaucrat.getName() << " couldn’t sign " <<_name << ", because grade isn't high enough." << std::endl;
        return;
    }
    _isSigned = true;
    std::cout << bureaucrat.getName() << " signed " << _name << std::endl;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form: " << form.getName() 
       << ", Signed: " << (form.isSigned() ? "Yes" : "No") 
       << ", Sign Grade: " << form.getSignGrade() 
       << ", Execute Grade: " << form.getExecuteGrade();
    return os;
}

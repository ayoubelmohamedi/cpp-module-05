/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:07:25 by ael-moha          #+#    #+#             */
/*   Updated: 2025/05/27 22:07:26 by ael-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "AForm.hpp"



AForm::AForm() : _name("default_form"), _isSigned(false), _signGrade(150), _executeGrade(150)
{
    std::cout << "Default constructor called: " << _name << ", sign grade " << _signGrade << ", execute grade " << _executeGrade << std::endl;
}

AForm::AForm(const std::string name, int signGrade, int executeGrade) 
    : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw AForm::GradeTooHighException();
    else if (signGrade > 150 || executeGrade > 150)
        throw AForm::GradeTooLowException();
    std::cout << "Constructor called: " << _name << ", sign grade " << _signGrade << ", execute grade " << _executeGrade << std::endl;
}

AForm::AForm(const AForm &other) 
    : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
    std::cout << "Copy constructor called: " << _name << ", sign grade " << _signGrade << ", execute grade " << _executeGrade << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
    std::cout << "Copy assignment operator called: " << _name << ", sign grade " << _signGrade << ", execute grade " << _executeGrade << std::endl;
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

AForm::~AForm()
{
    std::cout << "Destructor called for form: " << _name << std::endl;
}

std::string AForm::getName() const
{
    return _name;
}

bool AForm::isSigned() const
{
    return _isSigned;
}

int AForm::getSignGrade() const
{
    return _signGrade;
}

int AForm::getExecuteGrade() const
{
    return _executeGrade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
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

bool AForm::isExecutableBy(const Bureaucrat &bureaucrat) const
{
    if (!isSigned() || bureaucrat.getGrade() > _executeGrade)
        return (false);
    return true;
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed!";
}

const char *AForm::FormLowExecutionGradeException::what() const throw()
{
    return "Bureaucrat's grade is too low to execute this form!";
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "Form: " << form.getName() 
       << ", Signed: " << (form.isSigned() ? "Yes" : "No") 
       << ", Sign Grade: " << form.getSignGrade() 
       << ", Execute Grade: " << form.getExecuteGrade();
    return os;
}

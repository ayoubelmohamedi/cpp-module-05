/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:06:56 by ael-moha          #+#    #+#             */
/*   Updated: 2025/05/27 22:06:57 by ael-moha         ###   ########.fr       */
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

AForm* Intern::makeForm(const std::string _formName, const std::string target) const
{
    //todo: use data-driven approach 
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
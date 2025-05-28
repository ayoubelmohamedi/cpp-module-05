/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:06:58 by ael-moha          #+#    #+#             */
/*   Updated: 2025/05/28 19:46:45 by ael-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef INTERN_HPP
#define INTERN_HPP


#include <iostream>
#include <string>
#include <exception>
#include <AForm.hpp>


#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

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
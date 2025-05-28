/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:07:00 by ael-moha          #+#    #+#             */
/*   Updated: 2025/05/28 20:53:19 by ael-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp" 
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main ()
{
    // {"shrubbery creation", create_shrubby},
    // {"presidential pardon"

    try{
        Bureaucrat person1("John", 140);
        Intern intern1;
        AForm *form = intern1.makeForm("robotomy request", "Robot"); 
        if (form)
        {
            person1.signForm(*form);
            form->execute(person1);
            delete form;
        }
    }catch(const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}

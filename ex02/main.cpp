/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:07:34 by ael-moha          #+#    #+#             */
/*   Updated: 2025/05/29 00:24:50y ael-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp" 
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main ()
{
    try {


        std::cout << " =============CREATE BUREACRATS=================" << std::endl;
        Bureaucrat highGradeBureaucrat("HighGradeEmployee", 1);
        Bureaucrat midGradeBureaucrat("MidGradeEmployee", 70);
        Bureaucrat lowGradeBureaucrat("LowGradeEmployee", 150);
    
        std::cout << highGradeBureaucrat << std::endl;
        std::cout << midGradeBureaucrat << std::endl;
        std::cout << lowGradeBureaucrat << std::endl;

        
        std::cout << " ======================Shrubbery===================" << std::endl;
        ShrubberyCreationForm shrubForm("Garden");
        std::cout << shrubForm << std::endl;

        std::cout << "\\n* Low grade bureaucrat tries to sign and execute Shrubbery *" << std::endl;
        try {
            // Should fail: no enough grade to sign or execute
            lowGradeBureaucrat.signForm(shrubForm); 
            lowGradeBureaucrat.executeForm(shrubForm);
        } catch (const AForm::FormNotSignedException& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        } catch (const AForm::FormLowExecutionGradeException& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        std::cout << "-------------------->Second attempt<----------------------" << std::endl;

        std::cout << "\\n* Mid grade bureaucrat signs Shrubbery, Low grade tries to execute *" << std::endl;
        try {
            //mid grade can sign
            midGradeBureaucrat.signForm(shrubForm);
            std::cout << shrubForm << std::endl;
            //low grade cannot execute
            lowGradeBureaucrat.executeForm(shrubForm);
        }  catch (const AForm::FormNotSignedException& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        } catch (const AForm::FormLowExecutionGradeException& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }


        std::cout << "------------------->Thirsr attempt (works)<--------------------" << std::endl;
        std::cout << "\\n* Hight grade bureaucrat signs and exec Shrubbery*" << std::endl;
        try {
            highGradeBureaucrat.signForm(shrubForm);
            std::cout << shrubForm << std::endl;
            highGradeBureaucrat.executeForm(shrubForm);
        }  catch (const AForm::FormNotSignedException& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        } catch (const AForm::FormLowExecutionGradeException& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    
        std::cout << " =====================RobottomyRequest===================" << std::endl;

        std::cout << "\\n* Hight grade bureaucrat signs and execute RobottomyRequest *" << std::endl;
        RobotomyRequestForm robot("Robot");
        std::cout << robot << std::endl;
        try {
            //mid grade can sign
            highGradeBureaucrat.signForm(robot);
            std::cout << robot << std::endl;
            highGradeBureaucrat.executeForm(robot);
        }  catch (const AForm::FormNotSignedException& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        } catch (const AForm::FormLowExecutionGradeException& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        std::cout << " =========================PresidentialPardon====================" << std::endl;
        std::cout << "\\n* Hight grade bureaucrat signs and execute PresidentialPardon *" << std::endl;
        PresidentialPardonForm pardon("Judge"); 
        std::cout << pardon << std::endl;
        try {
            //mid grade can sign
            highGradeBureaucrat.signForm(pardon);
            std::cout << pardon << std::endl;
            highGradeBureaucrat.executeForm(pardon);
        }  catch (const AForm::FormNotSignedException& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        } catch (const AForm::FormLowExecutionGradeException& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }


        std::cout << " =====================END========================" << std::endl;
    } catch (Bureaucrat::GradeTooHighException& e)
    {   
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (Bureaucrat::GradeTooLowException& e)
    { 
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:07:00 by ael-moha          #+#    #+#             */
/*   Updated: 2025/05/28 23:46:08 by ael-moha         ###   ########.fr       */
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

    try{
        Bureaucrat person1("John", 5);
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
    catch (const AForm::FormNotSignedException& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }catch (const AForm::FormLowExecutionGradeException& e)
    { 
        std::cerr << "Exception: " << e.what() << std::endl;
    }


    std::cout << "=========================================" << std::endl;

    try{
        Bureaucrat person2("Bob", 5);
        Intern intern1;
        AForm *form = intern1.makeForm("shrubbery creation", "Garden"); 
        if (form)
        {
            person2.signForm(*form);
            form->execute(person2);
            delete form;
        }
    }catch(const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch (const AForm::FormNotSignedException& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }catch (const AForm::FormLowExecutionGradeException& e)
    { 
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "=========================================" << std::endl;

    try{
        Bureaucrat person3("Judge", 5);
        Intern intern1;
        AForm *form = intern1.makeForm("presidential pardon", "Corleone"); 
        if (form)
        {
            person3.signForm(*form);
            form->execute(person3);
            delete form;
        }
    }catch(const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch (const AForm::FormNotSignedException& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }catch (const AForm::FormLowExecutionGradeException& e)
    { 
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}

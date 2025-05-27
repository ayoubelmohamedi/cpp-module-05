/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:08:45 by ael-moha          #+#    #+#             */
/*   Updated: 2025/05/27 22:08:46 by ael-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Bureaucrat.hpp"

int main ()
{
    try
    {
        Bureaucrat defaultBureaucrat;
        Bureaucrat bureaucrat("John", 1);
        Bureaucrat c("Bob", 150);

        Bureaucrat b = bureaucrat;
        std::cout << b << std::endl;


        std::cout << bureaucrat << std::endl;
        std::cout << c << std::endl;
        std::cout << b << std::endl;

        defaultBureaucrat.incrementGrade();
        bureaucrat.incrementGrade();


    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}